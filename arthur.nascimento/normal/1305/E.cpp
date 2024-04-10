#include <bits/stdc++.h>
#define maxn 400400
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007 
#define debug(args...) //printf(args)
using namespace std;

vector<int> L[maxn];
int v[maxn];

main(){
    int n,m;
    scanf("%d%d",&n,&m);
    
    ll s = 0;
    vector<int> ans;
    int l = -1;
    for(int i=1;i<=n;i++){
       
        s += (i-1)/2;
        if(s > m){
              l = i;
            s -= (i-1)/2;
            break;
        }
         ans.pb(i);
        
    }
    
    if(ans.size() == n && s < m){
        printf("-1\n");
        return 0;
    }
    
    debug("s %lld l %d\n",s,l);
    
    int need = m - s;
    int has = (l-1)/2;
    int ii = l-1;
    while(has > need){
        l++;
        int fs = l - ii;
        int sz = ii-fs+1;
        has = sz/2;
    }
    
  if(ans.size() != n)  ans.pb(l);
    
    int u = 50000000;
    while(ans.size() < n){
        ans.pb(u);
        u += 5050;
    }
    
    for(int i : ans)
        printf("%d\n",i);
    
}