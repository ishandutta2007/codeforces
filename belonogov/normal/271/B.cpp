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
    #define epr 
#endif 


typedef long long ll;
typedef vector < int > vi;

const int maxn = 600;
const int inf = (int)1e9;

int a[maxn][maxn];
int b[3 * 1000 * 100];


bool check(int x){
    if (x < 2)
        return 0;
    for(int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    long long ans, sum, n, m;
    int x, last;
    cin >> n >> m;
    last = inf;
    for(int i = 2 * 1000 * 100; i >= 0; i--){
        if (check(i))
            last = i;
        b[i] = last - i;
        
    }
        
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &x);
            a[i][j] = b[x];
        }
//         epr("\n");
    }
    
    ans = inf;
    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = 0; j < m; j++)
            sum += a[i][j];
        ans = min(ans, sum);
    }
    
    for(int j = 0; j < m; j++){
        sum = 0;
        for(int i = 0; i < n; i++)
            sum += a[i][j];
        ans = min(ans, sum);
    }
    
    cout << ans << endl;
    
    return 0;
}