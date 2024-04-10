#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

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
ll n,m,k;
int main(){               
	cin>>n>>m>>k;
	if(k<n)
		return cout<<k+1<<" 1",0;
	k-=n;
	m--;
	cout<<n-k/m<<" ";
	if(k/m%2==0)       
		cout<<2+k%m;
	else
		cout<<m+1-k%m;
}