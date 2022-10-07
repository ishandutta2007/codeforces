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
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

ll read16() {
    string s;
    cin >> s;
    ll res = 0;
    for (auto ch: s) {
        int x = ch - '0';
        if ('a' <= ch && ch <= 'z')
            x = ch - 'a' + 10;
        res = res * 16 + x;
    }
    return res;
}

ll dp[100][2][2]; // pos eq ex


ll f(ll r) {
    ll answer = 0;
    vector<int> dig;
    for (; r > 0; r /= 16)
        dig.pb(r % 16);
    for (int i = 0; i < 5; i++)
        dig.pb(0);
    reverse(all(dig));
    //for (auto x: dig)
         //cerr << x << " ";
    //cerr << endl;
    for (int mx = 15; mx >= 0; mx--) {
        memset(dp, 0, sizeof(dp));
        dp[0][1][0] = 1;  
        int targetD = mx / 4;
        int bitId = mx % 4; 
        //db2(targetD, bitId);
        for (int i = 0; i < (int)dig.size(); i++) {
            bool flag = i + targetD + 1 == (int)dig.size();
            for (int t = 0; t < 2; t++) {
                for (int d = 0; d <= mx; d++) {
                    if (flag && ((d >> bitId) & 1) == 0)
                        continue;
                    dp[i + 1][0][t || (d == mx)] += dp[i][0][t];
                }
            }
            //db2(i, flag);

            for (int t = 0; t < 2; t++) {
                for (int d = 0; d <= min(mx, dig[i]); d++) {
                    //if (i == 6 && t == 1) {
                        //db3("tut", d, bitId);
                    //}


                    if (flag && ((d >> bitId) & 1) == 0) {
                        //if (i == 6 && t == 1) {
                            //db(d);
                        //}
                        continue;
                    }
                    dp[i + 1][(dig[i] == d)][t || (d == mx)] += dp[i][1][t];
                }
            }
        } 
        //db(dig.size()); 
        //db(dp[6][1][1]);
        //for (int t1 = 0; t1 < 2; t1++, cerr << endl)
            //for (int t2 = 0; t2 < 2; t2++, cerr << endl) 
                //for (int i = 0; i <= (int)dig.size(); i++) {
                    //cerr << dp[i][t1][t2] << " ";
                //}

        answer += dp[dig.size()][0][1];
        //db(answer);
        //exit(0);
    } 
    return answer;
}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    //db(f(21));
    //exit(0);
    int q;
    scanf("%d", &q);
    for (int tt = 0; tt < q; tt++) {
        ll l = read16();
        ll r = read16();
        //db2(l, r + 1);
        auto vr = f(r + 1);
        auto vl = f(l);
        //db2(vl, vr);
        printf("%lld\n", vr - vl);
    }
    



    return 0;
}