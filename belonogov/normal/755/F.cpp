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
#define prev prevv
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int n, k;
int p[N];
bool use[N];
bitset<N> dp;
int prev[N];

void read() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]); p[i]--;
    }
}

void solve() {
    vector<int> lens;
    for (int i = 0; i < n; i++) {
        if (!use[i]) {
            int v = i;
            int cnt = 0;
            for (; !use[v]; ) {
                use[v] = 1;
                cnt++;
                v = p[v];
            }
            lens.pb(cnt);
        }
    } 

    //for (auto x: lens)
        //db(x);


    int cntOdd = 0;
    for (auto x: lens)
        cntOdd += x % 2;

    int mn = 0, mx = 0;
    
    int b2 = (n - cntOdd) / 2;
    if (k <= b2) {
        mx = k * 2;
    }
    else {
        mx = min(b2 * 2 + k - b2, n);
    }

    //lens.clear();
    //n = 0;
    //for (int i = 1; i < 1500; i++) {
        //n += i;
        //lens.pb(i);
    //}
    //db(n);
        

    sort(all(lens));

    vector<int> g;
    for (int i = 0; i < (int)lens.size(); ) {
        int j = i;
        for (; i < (int)lens.size() && lens[j] == lens[i]; i++);
        int d = i - j;
        for (; d > 0; ) {
            g.pb((d + 1) / 2 * lens[j]);
            d -= (d + 1) / 2;
        }
        //sum += step * d;
        //for (int t = 0; t < step; t++) {
            //prev[t] = -INF;
        //}
        //for (int t = 0; t <= sum; t++) {
            //if (dp[t]) {
                //prev[t % step] = t / step;
            //}
            //else {
                //if (prev[t % step] + d >= t / step)
                    //dp[t] = 1;
            //}

        //}
    }

    dp[0] = 1;
    for (auto x: g)
        dp = dp | (dp << x);
    //for (int i = 0; i <= n; i++)
        //cerr << dp[i] << " ";
    //cerr << endl;
    
    //for (int i = 0; i <= n; i++)
        //cerr <

    //cerr << clock() * 1.0 /  CLOCKS_PER_SEC << endl;


    if (dp[k])
        mn = k;
    else
        mn = k + 1;

    cout << mn << " " << mx << endl;
}


void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    if (1) {
        read();
        solve();
    }
    else {
        stress();
    }

    return 0;
}