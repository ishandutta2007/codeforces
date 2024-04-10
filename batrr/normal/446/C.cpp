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
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=3e5+12,inf=1e9,LOG=18,mod=1e9+9;
pair< ll ,ll > t[4*maxn];
int n,q;
ll f1[maxn],f2[maxn],pref1[maxn],pref2[maxn],sum[4*maxn];
pair< ll,ll > getfib( pair<ll,ll> a, int len){
	return mp( ( f1[len]*a.f + f2[len]*a.s )%mod ,	( f1[len+1]*a.f + f2[len+1]*a.s )%mod ) ;
}
ll calc(pair<ll,ll> a,int l,int r){
	//cout<<a.f<<" "<<a.s<<" "<<l<<" "<<r<<endl;
	if(l==0)
		return ( ( (pref1[r])*a.f + (pref2[r])*a.s )%mod + mod ) %mod ;
	return ( ( (pref1[r]-pref1[l-1])*a.f + (pref2[r]-pref2[l-1])*a.s )%mod + mod ) %mod ;
}
void add(ll &a,ll x){
	a+=x;
	if(a>=mod)
		a-=mod;
}
void up(int v,int tl, int tr,int l, int r, pair< ll , ll > val,int bg){
	if(l>r)
		return ;
	if(tl==l && tr==r){
//		cout<<bg<<" "<<l<<" "<<r<<" "<<val.f<<" "<<val.s<<" ";
		val=getfib(val,l-bg);
//		cout<<val.f<<" "<<val.s<<endl;
		add(t[v].f,val.f);
		add(t[v].s,val.s);
		add(sum[v], calc(val,0,tr-tl) );
		return ;
	}
	int tm=(tl+tr)/2;             
	up(v+v,tl,tm,l,min(tm,r),val,bg);
	up(v+v+1,tm+1,tr,max(tm+1,l),r,val,bg);
	sum[v]=sum[v+v]+sum[v+v+1]+calc(t[v],0,tr-tl);
	sum[v]%=mod;
}
ll get(int v,int tl, int tr,int l, int r){
	if(l>r)
		return 0;
	if(tl==l && tr==r)
		return sum[v];
	int tm=(tl+tr)/2;             
	return ( get(v+v,tl,tm,l,min(tm,r)) + get(v+v+1,tm+1,tr,max(tm+1,l),r) +  calc(t[v],l-tl,r-tl) )%mod;
}
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
 	#endif  
 	f1[0]=1;
 	f1[1]=0;
 	f2[0]=0;
 	f2[1]=1;
 	pref1[0]=pref1[1]=pref2[1]=1;
 	for(int i=2;i<maxn;i++){        
 		f1[i]=(f1[i-1]+f1[i-2])%mod;
 		f2[i]=(f2[i-1]+f2[i-2])%mod;    
 		pref1[i]=(pref1[i-1]+f1[i])%mod;
 		pref2[i]=(pref2[i-1]+f2[i])%mod;
 	}
 	IOS
 	cin>>n>>q;
 	for(int i=1;i<=n;i++){
 		int x;
 		cin>>x;
 		up(1,1,n,i,i,mp(x,0),i);
 	}
 	
// 	for(int i=1;i<=n;i++)
 //			cout<<get(1,1,n,i,i)<<" ";cout<<endl;

	while(q--){
 		
 		int l,r,type;
 		cin>>type>>l>>r;
 		if(type==1)
 			up(1,1,n,l,r,mp(1,1),l);
 		else
 			cout<<(get(1,1,n,l,r)+mod)%mod<<endl;
 	
 	}
 	
 //	for(int i=1;i<=n;i++)
 //		cout<<get(1,1,n,i,i)<<" ";cout<<endl;

 	
}