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

const int maxn = (int)2e5;
const int inf = (int)1e9;

long long ans;

long long a[100][100];
int k;
void solve(long long t, int i){
    for(int kof = 0; t > 0; i--){
        if (1ll << i <= t){
            t -= (1ll << i);
            if (k - kof < 0)
    return;
            ans += a[i][k - kof];            
            kof++;
        }
    }
}



int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int i;
    long long n, t, d;
    cin >> n >> t; n++;
    for(k = 0; (t & 1) == 0; k++, t >>= 1);

//     epr("k %d\n", k);
    if (t != 1){
        printf("0\n");
        return 0;
    }
    d = 2;
    a[0][0] = 1;
//     epr("n %d\n", (int)n);
    for(i = 0; d * 2 - 1 <= n; d *= 2, i++){
        for(int j = 0; j <= i; j++)
            a[i + 1][j + 1] = a[i][j];
        for(int j = 0; j <= i + 1; j++)
            a[i + 1][j] += a[i][j]; 
        ans += a[i + 1][k];
    }  
//     epr("d %d\n", (int)d);
//     epr("i %d\n", (int)i);
//     cout << "first " << ans << endl;
    solve(n - (d - 1), i);
       
    cout << ans << endl;
    return 0;
}