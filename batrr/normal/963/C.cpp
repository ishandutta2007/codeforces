// Tima the best
#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
typedef complex < double > base ;
const ll maxn=2e5+123,inf=1e18,mod=1e9+7;
map< ll , map< ll, ll > >cnt;
set<ll>stw,sth;
ll n,g,ans,mnw,mnh;
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
    #endif                                     
	cin>>n;
	for(int i=1;i<=n;i++){
		ll w,h,c;
		cin>>w>>h>>c;
		
		if(g)
			g=__gcd(g,c);
		else
			g=c;
		
		stw.insert(w);
		sth.insert(h);
		cnt[w][h]=c;	
	}
	mnw=*stw.begin();
	mnh=*sth.begin();
	for( auto w:stw)
		for( auto h: sth )
			if( !cnt[w][h] )
				return cout<<0,0;
	//cout<<mnw<<" "<<mnh<<endl;
	for( auto w:stw)
		for( auto h: sth )
			if( cnt[mnw][h]*cnt[w][mnh] != cnt[w][h]*cnt[mnw][mnh] )
				return cout<<0,0;
	
	for(ll i=1;i*i<=g;i++)
		if( g%i==0 )
			ans+=2-(i*i==g);
	 
	cout<<ans;
}