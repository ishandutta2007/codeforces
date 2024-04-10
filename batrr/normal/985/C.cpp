// Tima the best
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 

#define ll long long                   
#define ld long double                
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e6,inf=1e8,mod=1e9+7,block=200,N=1e6;
ll n,m,k,l,a[maxn],ans;
bool used[maxn];
vector<ll>v;
int main(){
	
	#ifdef LOCAL
    	freopen ("test.in", "r", stdin);
	//#else
	//	freopen ("dictionary.in", "r", stdin);
	//	freopen ("dictionary.out", "w", stdout);
	#endif                            
	cin>>n>>k>>l;
	m=n*k;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	sort(a+1,a+1+m);
	for(int i=1;i<=m;i++)
		if( abs(a[1]-a[i])<=l )
			v.pb(a[i]);
	if( v.size() < n)
		return cout<<0,0;
	for(int i=0;i<v.size();i+=k){
		ans+=v[i];
		used[i]=1;
		n--;
	}
	for(int i=v.size()-1;i>=0;i--)
		if( !used[i] && n>0 )
			ans+=v[i],n--;
	 cout<<ans;
}