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
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;
ll n,k;
ll p,Q;

string  GET(ll l,ll r){
	if(l<=p && p<=r )
		return "Yes";
	return "No";
}
bool get(ll l,ll r){
	if( Q==4400 )
		assert(0);
	if(l>r)
    	cout<<l<<" "<<l<<endl;
	else
		cout<<l<<" "<<r<<endl;
	cout.flush();
	string s;
	cin>>s;
	//s=GET(l,r);
	//cout<<p<<endl;
	Q++;
	if(l==r && s=="Yes")
		exit(0);
	if(s=="Bad")
		exit(0);

	
	//vector<ll> pp;
	//for(ll i=max(1ll,p-k);i<=min(n,p+k);i++)
	//	pp.pb(i);
	//p=pp[rand()%pp.size()];
	
	return s=="Yes";
}
void seg(ll &l,ll &r){
   	if(l>r)
   		l=r;
   	l=max(l-k,1ll);
   	r=min(r+k,n);
}
int main(){
	IOS
    srand(time(0));
	cin>>n>>k;
    p=(1ll*rand()*rand())%n+1;
    ll l=1,r=n;
    while(true){
    	ll m=(l+r)/2;
    	if( get(l,m) )
    		r=m;
    	else
    		l=m+1;   
    	seg(l,r);
    	if(r-l<=4*k){
    	     	ll x=l+rand()%(r-l+1);
          	get(x,x);
     		seg(l,r);
     	}
     	
     	
     }
     
     return 0;
}