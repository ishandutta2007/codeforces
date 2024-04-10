#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;

signed main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        int sum=0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            sum+=v[i];
        }
        if(n==1){
            cout << 1 << "\n";
            continue;
        }
        int ans=0;
        int z=0;
        for(int i=0;i<n;i++){
            z+=v[i];
            if(z*2>sum){
                ans++;
            }
        }
        vector<int> pre(n),p2(n);
        pre[0]=p2[0]=v[0];
        p2[1]=v[1];
        pre[1]=pre[0]+v[1];
        for(int i=2;i<n;i++){
            pre[i]=pre[i-1]+v[i];
            p2[i]=p2[i-2]+v[i];
        }
        auto s1=[&](int l,int r){
            if(r<l){
                return 0ll;
            }
            int re=pre[r];
            if(l){
                re-=pre[l-1];
            }
            return re;
        };
        auto s2=[&](int l,int r){
            if(r<l){
                return 0ll;
            }
            int re=p2[r];
            if(l>=2){
                re-=p2[l-2];
            }
            return re;
        };
        const int mod=998244353;
        auto get=[&](int a,int l,int r){
            for(int i=l;i<=r;i++){
                int xl=i/2-1,xr=(r-i%2)/2;
                if((a+s2(i,i)+s1(i+1,r))*2<=sum){
                    continue;
                }
                while(xr>xl){
                    int m=(xl+xr+1)/2;
                    int z=a+s2(i,2*m+i%2)+s1(2*m+i%2+1,r);
                    if(2*z>sum){
                        xl=m;
                    }
                    else{
                        xr=m-1;
                    }
                }
                ans+=(xl-i/2+1);
                ans%=mod;
            }
        };
        get(v[0],2,n-2);
        get(v[0],2,n-1);
        get(0,1,n-2);
        get(0,1,n-1);
        cout << ans << "\n";
    }
    return 0;
}