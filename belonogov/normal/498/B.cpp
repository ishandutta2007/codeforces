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

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 

#define equal equalll
#define less lesss
const int N = 5555;
const int INF = 1e9 + 19;

bool equal(double a, double b) {
    return abs(a - b) < 1e-9;
}

bool lessE(double a, double b) {
    return a < b || equal(a, b);
}

double dp[N][N];
double p[N];
int t[N];
int n, T;
double pt[N];

void read() {
    scanf("%d%d", &n, &T);
    for (int i = 0; i < n; i++) {
        scanf("%lf%d", &p[i], &t[i]);
        p[i] /= 100;
    } 
}

void solve() {
    p[n] = 0;
    t[n] = T + 1;
    n++;
    for (int i = 0; i < n; i++) {
        pt[i] = 1;
        for (int j = 0; j < t[i] - 1; j++)
            pt[i] *= (1 - p[i]);
    }

    dp[0][0] = 1;
    double answer = 0;
    for (int i = 1; i <= n; i++) {
        double sum = 0;
        for (int j = 1; j <= T; j++) {
            //db2(i, j);
            sum += dp[i - 1][j - 1];  
            //db(sum);
            if (j - t[i - 1] >= 0)  {
                double x = dp[i - 1][j - t[i - 1]];
                dp[i][j] += pt[i - 1] * x;
                sum -= pt[i - 1] * x;
            }
            assert(lessE(0, sum));
                    
            dp[i][j] += sum * p[i - 1]; 
            sum -= sum * p[i - 1]; 
        }
        //db2(sum + dp[i][T], i);
        answer += (sum + dp[i - 1][T]) * (i - 1);
    }
    //for (int i = 0; i <= n; i++, cerr << endl)
        //for (int j = 0; j <= n; j++)
            //cerr << dp[i][j] << " ";

    //for (int i = 1; i <= n; i++)
        //answer += dp[i][T] * i;
    printf("%.17f\n", answer);
}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}