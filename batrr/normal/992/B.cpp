#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=1e5+123,inf=1e18,mod=1e9+7,N=360360;
ll x,y,l,r,ans;
vector<int> v;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    cin>>l>>r>>x>>y;
    if(y%x)
        return cout<<0,0;
    y/=x;
    for(int i=2;i*i<=y;i++){
        if(y%i==0){
            ll pw=1;
            while(y%i==0)  
                y/=i,pw*=i;
            v.pb(pw);
        }
    }
    if(y!=1)
        v.pb(y);

    for(int mask=0;mask<(1<<v.size());mask++){
        ll a=1,b=1;
        for(int i=0;i<v.size();i++)
            if( mask&(1<<i) )
                a*=v[i];
            else
                b*=v[i];
        if( l<=min(a,b)*x && x*max(a,b)<=r )
            ans++;
    }
    cout<<ans;
    #ifdef LOCAL
        cout <<endl<< clock () * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
}