#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

long long ans=0;
int main(){
    AquA;
    int n;
    cin >> n;  
    int m=n+n;
    vector<vector<int> > v(m);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ans=1ll*n*(n+1)*(n+2)/3*(n*(n-1)/2+n);
    for(int i=0;i<m;i++){
        vector<int> dis(m,1e9);
        vector<vector<int> > kk(n+1);
        dis[i]=0;
        queue<int> q;
        q.push(i);
        kk[0].push_back(i);
        while(q.size()){
            auto h=q.front();
            q.pop();
            for(auto a:v[h]){
                if(dis[a]==1e9){
                    dis[a]=dis[h]+1;
                    kk[dis[a]].push_back(a);
                    q.push(a);
                }
            }
        }
        int b=-1,c=n-1,d=n,e=m;
        for(int j=1;j<=n;j++){
            int mx=-1,mi=m;
            for(auto f:kk[j]){
                mx=max(mx,f);
                mi=min(mi,f);
            }
            if(mi>mx){
                break;
            }
            if(j==1){
                int z=mx-mi-1;
                int u=i;
                int k1=mi,k2=mx;
                if(k1>=n){
                    k1-=n;
                    k2-=n;
                }
                if(u>=n){
                    u-=n;
                }
                ans-=1ll*(u+1)*(n-u)*(z+z*(z-1)/2+k1+k1*(k1-1)/2+n-k2-1+(n-k2-1)*(n-k2-2)/2);
            }
            for(auto f:kk[j-1]){
                if(f<n){
                    d=min(d,f);
                    b=max(b,f);
                }
                else{
                    e=min(e,f);
                    c=max(c,f);
                }
            }
            if(j!=1){
                if(mi>=n){
                    if(mi>e && mi<c){
                        continue;
                    }
                    if(mx>e && mx<c){
                        continue;
                    }
                    int x,y;
                    if(mi>c){
                        x=n-1;
                        y=mi;
                    }
                    else if(mx<e){
                        x=mx;
                        y=m;
                    }
                    else{
                        x=mi;
                        y=mx;
                    }
                    ans-=1ll*(e-x)*(y-c)*(d+1)*(n-b);
                }
                else{
                    if(mi>d && mi<b){
                        continue;
                    }
                    if(mx>d && mx<b){
                        continue;
                    }
                    int x,y;
                    if(mi>b){
                        x=-1;
                        y=mi;
                    }
                    else if(mx<d){
                        x=mx;
                        y=n;
                    }
                    else{
                        x=mi;
                        y=mx;
                    }
                    ans-=1ll*(d-x)*(y-b)*(e-n+1)*(m-c);
                }
            }
        }
    }
    cout << ans/2 << "\n";
    return 0;
}