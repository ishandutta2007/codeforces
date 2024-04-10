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
#include <queue>

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

const int maxn = 1e6;
const int inf = (int)1e9;

int a[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    long long x, H;
    int n, m, h, w;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    H = 0;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &w, &h); w--;
        x = max((long long)a[w], H);
        cout << x << "\n";
        H = x + h;
    }
    

    return 0;
}