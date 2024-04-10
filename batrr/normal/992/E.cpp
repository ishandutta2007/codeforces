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

const ll maxn=2e5+123,inf=1e18,mod=1e9+7,N=360360;
ll n,q,a[maxn],t[4*maxn],add[4*maxn];
void up(int v,int tl, int tr,int l, int r, ll x){
    if(l>r)
        return ;
    if(tl==l && tr==r){
        t[v]+=x;
        add[v]+=x;
        return;
    }
    int tm=(tl+tr)/2;         
    up(v+v,tl,tm,l,min(tm,r),x);
    up(v+v+1,tm+1,tr,max(tm+1,l),r,x);
    t[v]=max(t[v+v],t[v+v+1])+add[v];
}
pair<ll,ll> get(int v,int tl, int tr,ll x){
    if(tl==tr)
            return mp(t[v]+x,tl);
    x+=add[v];
    int tm=(tl+tr)/2;
    if( t[v+v] < t[v+v+1] )
        return get(v+v+1,tm+1,tr,x);
    else
        return get(v+v,tl,tm,x);
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        up(1,1,n,i,n,-a[i]);
        up(1,1,n,i,i,2*a[i]);
    }
    while(q--){
        int i,x;
        scanf("%d%d",&i,&x);
        up(1,1,n,i,n,a[i]);
        up(1,1,n,i,i,-2*a[i]);
        a[i]=x;
        up(1,1,n,i,n,-a[i]);
        up(1,1,n,i,i,2*a[i]);
        vector< pair<ll,ll> >v;
        int ans=-1;
        while(true){
            pair<ll,ll> x=get(1,1,n,0);
            if( x.f>0 ){
                x.f++;
                up(1,1,n,x.s,x.s,-x.f);
                v.pb(x);
            }
            if( x.f==0 ){
                ans=x.s;
                break;
            }
            if( x.f<0 )
                break;

            if(v.size()>100)
                assert(0);
        }
        
        for(auto x:v)
            up(1,1,n,x.s,x.s,x.f);
        
        printf("%d\n",ans);
    }
    #ifdef LOCAL
        cout <<endl<< clock () * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
}