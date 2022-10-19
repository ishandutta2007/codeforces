#include <bits/stdc++.h>
#define maxn 400400
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007 
#define debug(args...) printf(args)
using namespace std;

vector<int> L[maxn];
vector<int> v;
void go(int vx,int p=0){
    for(int i:L[vx])
        if(i != p){
            go(i,vx);
        }
    v.pb(vx);
}

int dg[maxn];

main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b), a--, b--;
        L[a].pb(b);
        L[b].pb(a);
        dg[a]++;
        dg[b]++;
    }
    queue<int> Q;
    for(int i=0;i<n;i++){
        if(dg[i] == 1)
            Q.push(i);
    }
    
    while(Q.size()){
        int u = Q.front();
        Q.pop();
        v.pb(u);
        for(int i : L[u]){
            dg[i]--;
            if(dg[i] == 1) Q.push(i);
        }
    }
    
    for(int i=0;i<n;i+=2){
        if(i == n-1){
            printf("! %d\n",v[i]+1); break;
        }
        int a = v[i]+1, b = v[i+1]+1;
        printf("? %d %d\n",a,b); fflush(stdout);
        int u;
        scanf("%d",&u);
        if(u == a) {
            printf("! %d\n",a); fflush(stdout); break;
        }
        if(u == b){
            printf("! %d\n",b); fflush(stdout); break;
        }
        
        
    }
}