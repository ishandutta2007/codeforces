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
const int N = 222;
const int F = 30;
const ll INF = 1.01e9;
typedef vector<int> vi;



int dp1[N][N * F];
int dp2[N][N * F];

void upd(int& a, int b) {
    a = max(a, b);
}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> d2(n);
    vector<int> d5(n);
    for (int i = 0; i < n; i++) {
        ll x;
        scanf("%lld", &x);
        for (; x % 5 == 0; x /= 5) {
            d5[i]++;
        }
        for (; x % 2 == 0; x /= 2) {
            d2[i]++;
        }
    } 
    memset(dp1, -63, sizeof(dp1));
    dp1[0][0] = 0;
    for (int i = 0; i < n; i++) {
        memset(dp2, -63, sizeof(dp2));
        for (int j = 0; j <= k; j++) {
            for (int t = 0; t <= j * F; t++) {
                upd(dp2[j][t], dp1[j][t]);
                upd(dp2[j + 1][t + d5[i]], dp1[j][t] + d2[i]);
            }
        }
        memcpy(dp1, dp2, sizeof(dp2));
    }
    int answer = 0;
    for (int i = 0; i < k * F; i++)
        answer = max(answer, min(i, dp1[k][i]));

    cout << answer << endl;

     

    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}