#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 1e6 + 5;
const int inf = 1e9;

int a[maxn];
int b[maxn];
int c[30];
int d[30];
int e[30];


bool solve(int k){
    long long sum = 0;
    for(int i = 0; i < 30; i++)
    d[i] = c[i];
    memset(e, 0, sizeof(e));
    for(int i = 0; i < k; i++)
    e[b[i]]++;

    for(int i = 29; i >= 0; i--){
    sum += d[i];
    sum -= e[i];
    if (sum < 0) return 0;
    sum *= 2;
    }
    return 1;   
}



int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);
    for(int i = 0; i < m; i++)
    scanf("%d", &b[i]);
   
    for(int i = 0; i < n; i++)
    for(int j = 0; a[i]; j++, a[i] /= 2)
        c[j] += a[i] & 1;
    
    
    sort(b, b + m);
    int l = 0, r = m + 1;
    while (r - l > 1){
    if (solve((l + r) / 2))
        l = (l + r) / 2;
    else
        r = (l + r) / 2;
    }
    printf("%d\n", l);
    
    
    return 0;
}