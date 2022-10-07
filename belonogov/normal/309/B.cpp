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

char t[maxn * 6];
char * s[maxn];
int a[maxn];
int pref[maxn];
int go[maxn];
vector < int > e[maxn];
bool use[maxn];
int stack[maxn];
int uk;
int ans = 0;
int start = -1;
int r, c;


void dfs(int v){
    use[v] = 1;
    stack[uk++] = v;
    for(int i = 0; i < (int)e[v].size(); i++)
    dfs(e[v][i]);
    if (stack[max(uk - 1 - r, 0)] - v > ans){
    start = v;
    ans = stack[max(uk - 1 - r, 0)] - v;
    }    
    uk--;
}



inline int getsum(int l, int r){
    return pref[r] - pref[l];
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n;
    int cur;
    char * s1 = t;
    scanf("%d%d%d", &n, &r, &c);
    c++;
    for(int i = 0; i < n; i++){
    scanf("%s", s1);
    s[i] = s1; 
    a[i] = strlen(s[i]) + 1;
    s1 += a[i];
    }
    for(int i = 0; i < n; i++)
    pref[i + 1] = pref[i] + a[i];

    cur = 0;
    for(int i = 0; i < n; i++){
    cur = max(cur, i);
    for(; cur < n && getsum(i, cur + 1) <= c; cur++);   
    go[i] = cur;
    if (cur != i)
        e[cur].pb(i);
    }

    for(int i = n; i >= 0; i--)
    if (!use[i]){
        uk = 0;
        dfs(i);
    }
    int v = start;
    for(; v != start + ans; ){
    for(int i = v; i < go[v]; i++){
        printf("%s", s[i]);
        if (i + 1 != go[v])
        printf(" ");
    }
    printf("\n");
    v = go[v];
    }


 
    return 0;
}