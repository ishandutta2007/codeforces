#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
int n;
vector < bool > use(100100, 0), use2(100100, 0);
vector < int > v[100100], ans;
bool dfs(int k){
    if(use[k]) return 0;
    use[k] = 1;
    bool ok = 0;
    for(int i = 0; i<v[k].size(); i++){
        if(dfs(v[k][i])){
            ok = 1;
        }
    }
    if(use2[k]){
        if(!ok) ans.pb(k);
        return 1;
    }
    return ok;
}
int main () {
    cin >> n;
    n--;
    for(int i = 0; i<n; i++){
        int l, r, t;
        scanf("%d%d%d", &l, &r, &t);
        l--;
        r--;
        v[l].pb(r);
        v[r].pb(l);
        if(t == 2){
            use2[l] = 1;
            use2[r] = 1;
        }
    }
    dfs(0);
    printf("%d\n", ans.size());
    for(int i = 0; i<ans.size(); i++){
        printf("%d ", ans[i]+1);
    }
    return 0;
}