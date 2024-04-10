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
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const int INF = 1.01e9;
typedef vector<int> vi;



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<int> dp(n + 1);
    vector<int> par(n + 1);

    for (int i = 1; i <= n; i++) {
        int res = INF;
        int how = -1;
        for (int j = 2;; j++) {
            int cost = j * (j - 1) / 2;
            if (cost > i) break;
            if (res > dp[i - cost] + 1) {
                res = dp[i - cost] + 1;
                how = j;
            }
        }
        assert(how != -1);
        dp[i] = res;
        par[i] = how;
    } 

    string answer = "z";
    int cur = 0;
    int pos = n;
    for (; pos != 0; ) {
        int y = par[pos];
        forn(_, y)
            answer.pb('a' + cur);
        cur++;
        pos -= y * (y - 1) / 2;
    }
    cout << answer << endl;








    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}