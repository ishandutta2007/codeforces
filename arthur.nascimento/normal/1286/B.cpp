#include <bits/stdc++.h>
#define maxn 400400
#define pb push_back
#define ll long long
#define debug 
#define pii pair<int,int>
using namespace std;

vector<int> L[maxn];
int c[maxn];
int ans[maxn];
int sz[maxn];

void go0(int vx){
    sz[vx] = 1;
    for(int i=0;i<L[vx].size();i++){
        go0(L[vx][i]);
        sz[vx] += sz[L[vx][i]];
    }
}

void go(int vx,vector<int> v){
    if(c[vx] >= v.size()){
        printf("NO\n");
        exit(0);
    }
    ans[vx] = v[c[vx]];
    swap(v[c[vx]], v[v.size()-1]);
    v.pop_back();
    for(int i=0;i<L[vx].size();i++){
        vector<int> h;
        for(int j=0;j<sz[L[vx][i]];j++){
            h.pb(v[v.size()-1]);
            v.pop_back();
        }
        sort(h.begin(),h.end());
        go(L[vx][i],h);
    }
}

main(){
    
    int n;
    scanf("%d",&n);
    int rt;
    for(int i=0;i<n;i++){
        int p;
        scanf("%d%d",&p,c+i), p--;
        if(p == -1) rt = i;
        L[p].pb(i);
    }
    
    vector<int> v;
    for(int i=1;i<=n;i++) v.pb(i);
    go0(rt);
    go(rt,v);
    printf("YES\n");
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
    printf("\n");
}