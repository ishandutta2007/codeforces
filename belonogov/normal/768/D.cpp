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
const int N = 1111; 
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


int k, q;
double dp[N * 9][N];

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    scanf("%d%d", &k, &q);
    int n = 9000;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i + 1][j + 1] += (k - j) * 1.0 / k * dp[i][j];
            dp[i + 1][j] += j * 1.0 / k * dp[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        double x;
        scanf("%lf", &x);
        //x /= 2000;
        int cur = 0;
        double eps = 1e-7;
        for (; dp[cur][k] < (x - eps) / 2000; cur++);
        //cerr << dp[cur - 1][k] << " ";
        //cerr << dp[cur][k] << " ";
        //cerr << dp[cur + 1][k] << " ";
        //cerr << endl;
        printf("%d\n", cur);
    }


    return 0;
}