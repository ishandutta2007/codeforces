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

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
#define next nexttt
const int N = 2222;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int ALF = 26;

int n;
string s[N];
vector<vector<int>> nextS[N];
int m;
int id[N];
string t;
pair<int,int> dp[N][N];
vector<vector<int>> nextT;
pair<int,int> nextG[N][ALF];


void read() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &id[i]);
        id[i]--;
    }
    cin >> t;

}

void calcNext(string ss, vector<vector<int>> &a) {
    int nn = ss.size();
    a.resize(nn + 1, vector<int>(ALF, INF));
    for (int i = nn - 1; i >= 0; i--) {
        for (int j = 0; j < ALF; j++) 
            a[i][j] = a[i + 1][j];
        a[i][ss[i] - 'a'] = i;
    }
}

void upd(pair<int,int> &A, pair<int,int>  B) {
    A = min(A, B);
}

int solve() {
    memset(dp, 63, sizeof(dp));
    dp[0][0] = mp(0, 0);
    for (int i = 0; i < n; i++)
        nextS[i].clear();
    nextT.clear();

    //db2(n, m);
    //db2(s[0], t);
    //db(id[0]);

    calcNext(t,  nextT);
    for (int i = 0; i < n; i++) {
        calcNext(s[i], nextS[i]);
    }
    memset(nextG, 63, sizeof(nextG));
    
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < ALF; j++)
            nextG[i][j] = nextG[i + 1][j];  
        for (int j = 0; j < ALF; j++)
            if (nextS[id[i]][0][j] != INF)
                nextG[i][j] = mp(i, nextS[id[i]][0][j]);
    }
    //for (int i = 0; i <= n; i++, cerr << endl)
        //for (int j = 0; j < 5; j++)
            //cerr << "(" << nextG[i][j].F << ", " << nextG[i][j].S << ") ";


    for (int i = 0; i < (int)t.size(); i++) {
        for (int j = 0; j <= i; j++) {
            if (dp[i][j].F < INF) {
                int x = dp[i][j].F;
                int y = dp[i][j].S;
                for (int ch = 0; ch < ALF; ch++) {
                    if (nextT[i][ch] < INF) {
                        //db3(i, j, ch);
                        pair<int,int> p2;
                        //db2(x, y);
                        if (nextS[id[x]][y][ch] < INF) {
                            p2 = mp(x, nextS[id[x]][y][ch]);
                        }
                        else {
                            p2 = nextG[x + 1][ch];
                        }
                        //db2(p2.F, p2.S);
                        if (p2.F < INF) {
                            p2.S++;
                            upd(dp[nextT[i][ch] + 1][j + 1], p2);
                        }
                    }
                } 
            }
        }
    }
    //for (int i = 0; i <= (int)t.size(); i++, cerr << endl)
        //for (int j = 0; j <= (int)t.size(); j++)
            //cerr << "(" << dp[i][j].F << ", " << dp[i][j].S << ") ";


    int answer = 0;
    for (int pos = 0; pos <= (int)t.size(); pos++)
        for (int i = 0; i <= (int)t.size(); i++)
            if (dp[pos][i].F < INF)
                answer = max(i, answer);

    //cout << answer << endl;
    return answer;
}

int dp2[N][N];
void upd(int &A, int B) {
    A = max(A, B);
}

int stupid() {
    string tmp;
    for (int i = 0; i < m; i++)
        tmp += s[id[i]];
    n = 1;
    s[0] = tmp;
    m = 1;
    id[0] = 0;
    //db(tmp);
    dp2[0][0] = 0;
    for (int i = 0; i <= (int)s[0].size(); i++)
        for (int j = 0; j <= (int)t.size(); j++) {
            if (i == 0 && j == 0) continue;
            dp2[i][j] = -INF;
            if (i > 0)
                upd(dp2[i][j], dp2[i - 1][j]);
            if (j > 0)
                upd(dp2[i][j], dp2[i][j - 1]);
            if (i > 0 && j > 0 && s[0][i - 1] == t[j - 1])
                upd(dp2[i][j], dp2[i - 1][j - 1] + 1);
        }  
    return dp2[s[0].size()][t.size()];
    //return solve();
}


void printAns(int xx) {
    printf("%d\n", xx);
}

void genTest() {
    int T = 6;
    n = rand() % T + 1;
    for (int i = 0; i < n; i++) {
        int len = rand() % T + 1;
        s[i] = "";
        for (int j = 0; j < len; j++)
            s[i] += 'a' + rand() % T;
    }
    m = rand() % T + 1;
    for (int i = 0; i < m; i++)
        id[i] = rand() % n;
    int len = rand() % T + 1;
    t = "";
    for (int i = 0; i < len; i++)
        t += 'a' + rand() % T;
}

void printTest() {
    cout << n << endl;
    for (int i = 0; i < n; i++)
        cout << s[i] << endl;
    cout << m << endl;
    for (int i = 0; i < m; i++)
        cout << id[i] + 1 << " ";
    cout << endl;
    cout << t << endl;

}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        genTest();
        //printTest();
        auto r1 = solve();
        auto r2 = stupid();
        db2(r1, r2);
        assert(r1 == r2);
    }

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    if (1) {
        read();
        printAns(solve());
        //printAns(stupid());
    }
    else {
        stress();
    }

    return 0;
}