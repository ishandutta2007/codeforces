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
ll n,q,x,k,a[maxn];
int main(){ 
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	while(q--){
		cin>>x;
		k+=x;
		if(k>=a[n])
			k=0;
		int l=0,r=n;
		while(l<=r){
			int m=(l+r)/2;
			if(a[m]<=k)
				l=m+1;
			else
				r=m-1;	
		}
		cout<<n-l+1<<endl;
	}
}