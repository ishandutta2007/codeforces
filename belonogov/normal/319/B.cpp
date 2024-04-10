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

const int maxn = 2e5;
const int inf = 1e9;


int a[maxn];
vector < int > b1;
vector < int > b2;
int next[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, v, step, ans, u;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);
    for(int i = 0; i < n - 1; i++)
    if ((i == 0 || a[i - 1] < a[i]) && a[i] > a[i + 1])
        b1.pb(i);
    for(int i = 0; i < n; i++)
    next[i] = i + 1;
    next[n - 1] = -1;
    
    for(ans = 0; b1.size() != 0; ans++){
//  for(int i = 0; i < (int)b1.size(); i++)
//      epr("%d ", b1[i]);
//  epr("\n");
    b2.clear();
    for(int i = 0; i < (int)b1.size(); i++){
        u = v = b1[i];
        for(step = 0; next[v] != -1 && a[next[v]] < a[v]; step++){
        int oldv = v;
        v = next[v];
        next[oldv] = -1;
//      epr("oldv-1 %d\n", oldv);
        }
       
        next[u] = next[v];
//      epr("u next v %d %d \n", u, next[v]); 
        if (next[u] != -1 && a[u] > a[next[u]])
        b2.pb(u);
    }   
    swap(b1, b2);
//  epr("next : ");
//  for(int i = 0; i < n; i++)
//      epr("%d ", next[i]);
//  epr("\n");
    } 
    printf("%d\n", ans);
    
    return 0;
}