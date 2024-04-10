#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 3e5 + 10;
typedef long long ll;
const ll LOG = 20;

//ll n;
//ll a[3][N];
//pair<ll,ll> dp[2][N];
//ll go[3][N];
//int jump[LOG][3][N];

void upd(pair<int,int>& A, pair<int,int> B) {
    if (A.F < B.F || (A.F == B.F && A.S > B.S)) {
        A = B;
    }
}

//pair<ll,ll> fastMove(ll pos, ll type, ll bound, vector<vector<vector<int>>> jump) {
pair<ll,ll> fastMove(ll pos, ll type, ll bound, vector<vector<vector<int>>>& jump) {
    ll res = 0;
    for (ll i = LOG - 1; i >= 0; i--) {
        if (jump[i][type][pos] != -1 && jump[i][type][pos] <= bound) {
            res += pw(i);
            pos = jump[i][type][pos];
        }
    }
    return mp(res, pos);
}


ll solve(vector<vector<ll>> a) {
    int n = a[0].size();
    for (ll i = 0; i < n; i++) {
        a[2][i] = a[0][i] + a[1][i];
    }
    //memset(go, -1, sizeof go);
    vector<vector<int>> go(3, vector<int> (n, -1));
    for (ll j = 0; j < 3; j++) {
        map<ll,ll> q;
        ll sum = 0;
        for (ll i = 0; i <= n; i++) {
            if (q.count(sum) == 1) {
                ll prev = q[sum];
                //db(prev);
                go[j][prev] = i;
            } 
            q[sum] = i;
            if (i < n)
                sum += a[j][i];
        }
    }

    //db(n);
    //for (ll j = 0; j < 3; j++, cerr << endl)
        //for (ll i = 0; i < n; i++)
            //cerr << go[j][i] << " ";

    //db("done");
    //memset(jump, -1, sizeof jump)
    vector<vector<vector<int>>> jump(LOG, vector<vector<int>>(3, vector<int>(n + 1, -1)));
    for (ll j = 0; j < 3; j++) {
        ll up = -1;
        for (ll i = n - 1; i >= 0; i--) {      
            if (go[j][i] != -1 && (up == -1 || up > go[j][i])) {
                up = go[j][i];
            }
            jump[0][j][i] = up;
            for (ll t = 1; t < LOG; t++) {
                if (jump[t - 1][j][i] != -1) {
                    //db("!!");
                    jump[t][j][i] = jump[t - 1][j][jump[t - 1][j][i]];
                }
            }
        }  
    }
    //for (ll j = 0; j < 3; j++, cerr << endl)
        //for (ll i = 0; i <= n; i++)
            //cerr << jump[0][j][i] << " ";

    //db(jump[0][0][0]);

    //memset(dp, -1, sizeof(dp));
    vector<vector<pair<int,int>>> dp(2, vector<pair<int,int>>(n + 1, mp(-1,-1)));
    //db("dp");

    dp[0][0] = mp(0, 0);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < 2; j++) {
            if (dp[j][i].F == -1) continue;
            //if (go[2][i] != -1) {
            if (jump[0][2][i] != -1) {
                ll pos = jump[0][2][i];
                upd(dp[0][pos], mp(dp[j][i].F + 1, pos));
                upd(dp[1][pos], mp(dp[j][i].F + 1, pos));
            }
            //if (go[j][i] != -1) {
            if (jump[0][j][i] != -1) {
                ll pos = jump[0][j][i];
                auto res = fastMove(dp[j][i].S, j ^ 1, pos, jump);
                ll nCnt = dp[j][i].F + 1 + res.F;

                //if (j == 0 && i == 1) {
                    //db2("!", pos);
                    //db2(res.F, res.S);
                    //db2(nCnt, res.S);
                    //db2(j, pos);
                //}

                upd(dp[j][pos], mp(nCnt, res.S));
            }
            //if (go[j ^ 1][dp[j][i].S] != -1) {
            if (jump[0][j ^ 1][dp[j][i].S] != -1) {
                ll pos = jump[0][j ^ 1][dp[j][i].S];
                //db2(pos, i);
                assert(pos > i);
                auto res = fastMove(i, j, pos, jump); 
                ll nCnt = dp[j][i].F + 1 + res.F;
                upd(dp[j ^ 1][pos], mp(nCnt, res.S));
            }
        }     
    }
    //auto pp = [&](int i, int j) {
        //cerr << "i j: " << i << " " << j << "       ";
        //cout << "cnt pos: " << dp[i][j].F << " " << dp[i][j].S << endl;
    //};

    //pp(0, 1);
    //pp(0, 3);
    //db(fastMove(1, 1, 3, jump).F);
    //db(fastMove(1, 1, 3, jump).S);

    //db(dp[0][0].F, dp[0][0].S);

    int answer = 0; 
    for (ll i = 0; i <= n; i++)
        for (ll j = 0; j < 2; j++)
            answer = max(answer, dp[j][i].F);
    return answer;
}

vector<vector<ll>> genTest() {
    int n = rand() % 5 + 1;
    int H = 100;
    ll T = 100 % H + 1;
    vector<int> g;
    int F = 10;
    for (int i = 0; i < T; i++) {
        g.pb(rand() % F);
    }

    vector<vector<ll>> a(3, vector<ll>(n));
    for (ll j = 0; j < 2; j++)
        for (ll i = 0; i < n; i++) {
            a[j][i] = g[rand() % g.size()] * ((rand() % 2 == 1)? -1: 1);
        }
    return a;
}

ll slowAns;

void gen(int p1, int p2, ll cnt, vector<vector<ll>> &a) {
    //db3(p1, p2, cnt);
    slowAns = max(slowAns, cnt);
    int n = a[0].size();

    for (int i = max(p1, p2); i < n; i++) {
        ll sum = 0;
        for (int len = 1; i + len <= n; len++) {
            sum += a[0][i + len - 1];
            sum += a[1][i + len - 1];
            if (sum == 0) {
                gen(i + len, i + len, cnt + 1, a);
            }
        }
    }
    for (int i = p1; i < n; i++) {
        ll sum = 0;
        for (int len = 1; i + len <= n; len++) {
            sum += a[0][i + len - 1];
            if (sum == 0) {
                gen(i + len, p2, cnt + 1, a);
            }
        }
    }

    for (int i = p2; i < n; i++) {
        ll sum = 0;
        for (int len = 1; i + len <= n; len++) {
            sum += a[1][i + len - 1];
            if (sum == 0) {
                gen(p1, i + len, cnt + 1, a);
            }
        }
    }
}

int slow(vector<vector<ll>> a) {
    slowAns = 0;
    gen(0, 0, 0, a); 
    return slowAns;
}

int slow2(vector<vector<ll>> a) {
    int n = a[0].size();
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    auto upd2 = [](int& A, int B) {
        A = max(A, B);
    };

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            if (i + 1 <= n) upd2(dp[i + 1][j], dp[i][j]);
            if (j + 1 <= n) upd2(dp[i][j + 1], dp[i][j]);

            int p = max(i, j);
            ll sum = 0;
            for (int len = 1; len + p <= n; len++) {
                sum += a[0][p + len - 1];
                sum += a[1][p + len - 1];
                if (sum == 0)
                    upd2(dp[p + len][p + len], dp[i][j] + 1);
            }
            sum = 0;
            for (int len = 1; len + i <= n; len++) {
                sum += a[0][i + len - 1];
                if (sum == 0)
                    upd2(dp[i + len][j], dp[i][j] + 1);
            }
            sum = 0;
            for (int len = 1; len + j <= n; len++) {
                sum += a[1][j + len - 1];
                if (sum == 0)
                    upd2(dp[i][j + len], dp[i][j] + 1);
            }
        }


    int mx = 0;
    for (auto x: dp)
        for (auto y: x)
            mx = max(mx, y);
    return mx;

}

void printTest(vector<vector<ll>> a) {
    int n = a[0].size();
    cout << n << endl;
    for (int j = 0; j < 2; j++, cerr << endl)
        for (int i = 0; i < n; i++)
            cout << a[j][i] << " ";
    cout << endl;
}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        auto a = genTest();
        printTest(a);
        auto r1 = solve(a);
        //auto r2 = slow(a);
        auto r3 = slow2(a);
        //db2(r1, r3);
        //assert(r1 == r2);
        db2(r1, r3);
        assert(r1 == r3);
    }
}

int main(){
#define TASK "D"
#ifdef HOME 
    assert(freopen(TASK".in", "r", stdin));
    //assert(freopen(TASK".out", "w", stdout));
#endif
   //db("done");
    if (1) {
        int n;
        scanf("%d", &n);
        //db(n);
        vector<vector<ll>> a(3, vector<ll>(n));
        for (ll j = 0; j < 2; j++)
            for (ll i = 0; i < n; i++) {
                //db2(j, i);
                scanf("%lld", &a[j][i]);
            }
        //db("GGG");
        int answer = solve(a);
        //db(slow2(a));
        //db(slow(a));
        printf("%d\n", answer);
    }
    else {
        stress();
    }
   
    
//#ifdef HOME 
    //epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
//#endif
    return 0;
}