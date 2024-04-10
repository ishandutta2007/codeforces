#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>


using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr ()
#endif 


typedef long long ll;
typedef vector < int > vi;

const int maxn = 5000 + 10;
const int inf = (int)1e9;

int a[maxn];
int b[maxn];
int dp[maxn][maxn];


int main(){
//     freopen("in", "r", stdin);
 //   freopen("out", "w", stdout);
    int n, m;
    double x;    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> x;
        
    for(int i = 0; i < n; i++)
        b[i] = a[i];

    sort(b, b + n);
    for(int i = 0; i < n + 1; i++)
        for(int j = 0; j < n + 1; j++){
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            dp[i][j + 1] = max(dp[i][j +  1], dp[i][j]);
            if (a[i] == b[j])
    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
        }
   /* epr("\na\n");
    for(int i = 0; i < n; i++)
        epr("%d ", a[i]);
    epr("\nb\n");
    for(int i = 0; i < n; i++)
        epr("%d ", b[i]);
    epr("\n\n");
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < n + 1; j++)
            epr("%d ", dp[i][j]);
        epr("\n");
    }
   */ cout << n - dp[n][n] << endl;
        
        
    
    
    return 0;
}