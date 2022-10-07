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
#define less lesss
#define great greatttt

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr 
#endif 

const int maxn = 2e5;
const int inf = (int)1e9;

int a[maxn];
int less[maxn];
int great[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, m, d, l, r;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    d = -1;
    less[0] = -1;
    for(int i = 1; i < n; i++){
        if (a[i - 1] < a[i]) d = i - 1;
        less[i] = d;
    }
    d = inf;
    great[n - 1] = inf;
    for(int i = n - 2; i >= 0; i--){
        if (a[i] > a[i + 1]) d = i;
        great[i] = d;
    }
//     for(int i = 0; i < n; i++)
//         epr("%d ", less[i]);
//     epr("\n");
//     
//     for(int i \= 0; i < n; i++)
//         epr("%d ", great[i]);
//     epr("\n");
    
    for(int i = 0; i < m; i++){
        scanf("%d%d", &l, &r); l--; r--;
        cout << ((less[r] > great[l]) ? "No" : "Yes") << endl;
    }
    return 0;
}