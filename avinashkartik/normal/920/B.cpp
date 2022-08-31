#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
#define N (int)1e3+3

ll n,x[3];
queue <pair<ll,ll>> q;
ll ans[N],a[N][3];

int main(){ 
    ll t;
    cin>>t;
    while(t--){
        cin>>n;
        fill_n(ans,N,0);
        fill_n(a[0],N,0);
        fill_n(a[2],N,0);
        for(int i = 0; i<n; i++){
            cin>>a[i][0]>>a[i][2];
            a[i][1] = i+1;
        }
        ll i = 0;
        ll time = 1;
        //cout<<ans[1];
        while(time <= 5000){
            while(i < n && a[i][0] == time){
                q.push({a[i][1],a[i][2]});
                i += 1;
            }
            while(true){
                if(!q.empty()){
                    x[1] = q.front().first;
                    x[2] = q.front().second;
                    q.pop();
                    if(x[2] >= time){
                        //cout<<x[2]<<' '<<time<<endl;
                        ans[x[1]] = time;
                        break;
                    }
                }
                else
                    break;
            }
            time += 1;
        }
        for(int i = 1; i<=n; i++)
            printf("%lld ",ans[i]);
        printf("\n");
        while(!q.empty()) q.pop();
    }
}