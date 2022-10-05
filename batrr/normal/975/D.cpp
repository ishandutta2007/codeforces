#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define nm "A" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO stdi stdo                   
#define ll long long                   
#define ld long double                                                                                                           
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=5e5+123,MX=1e9,inf=1e9,block=2;
ll ans,n,a,b,x[maxn],vx[maxn],vy[maxn];
map<ll,ll>cnt1;
map<pair<ll,ll>,ll>cnt2,cnt3,cnt4;
int main(){        
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>vx[i]>>vy[i];
		cnt1[vx[i]*a-vy[i]]++;          
		cnt2[mp(vx[i]*a-vy[i],vx[i])]++;
		cnt3[mp(vx[i]*a-vy[i],vy[i])]++;
		cnt4[mp(vx[i],vy[i])]++;
	}                                                   
	for( map<ll,ll> :: iterator it=cnt1.begin();it!=cnt1.end();it++)
		ans+=(*it).s*((*it).s-1);

	for( map<pair<ll,ll>,ll> :: iterator it=cnt2.begin();it!=cnt2.end();it++)
		ans-=(*it).s*((*it).s-1);

	for( map<pair<ll,ll>,ll> :: iterator it=cnt3.begin();it!=cnt3.end();it++)
		ans-=(*it).s*((*it).s-1);
	
	for( map<pair<ll,ll>,ll> :: iterator it=cnt4.begin();it!=cnt4.end();it++)
		ans+=(*it).s*((*it).s-1);
	cout<<ans;
}