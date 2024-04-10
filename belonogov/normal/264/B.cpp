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

int b[maxn];
int a[maxn];

int main(){
//     freopen("in", "r", stdin);
  //  freopen("out", "w", stdout);
    int res, ans = 0, d, n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    for(int i = 0; i < n; i++){
        res = 0;
        d = a[i];
        for(int j = 2; j * j <= d; j++){
            if (d % j == 0)
    res = max(res, b[j]);
            assert(d != 0);
            for(; d % j == 0; d /= j);
        }
        if (d > 1)
            res = max(res, b[d]);
        res++;
      
        d = a[i];
        for(int j = 2; j * j <= d; j++){
            if (d % j == 0)
    b[j] = max(res, b[j]);
            assert(d != 0);
            for(; d % j == 0; d /= j);
        }
        if (d > 1)
            b[d] = max(res, b[d]);
      
     
        ans = max(res, ans);      
       
        
        
//         epr("\nb\n");
//         for(int i = 0; i < 10; i++)
//         epr("%d ", b[i]);
//         epr("\n");
//     
//         epr("%d ", res);
    }
   
   
   
    
    cout << ans << endl;
    
    
    
    
    return 0;
}