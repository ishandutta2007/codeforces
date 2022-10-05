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
const ll maxn=1e6+123,MX=1e9,inf=1e9,block=2;
ll n,x1,x2;
pair<ll,ll>a[maxn];
int main(){                                               
	cin>>n>>x1>>x2;
	for(int i=1;i<=n;i++){
		cin>>a[i].f;
		a[i].s=i;
	}
	sort(a+1,a+1+n);                         
	for(int i=1,j=n;i<=n;i++){           
		while(a[i].f*j>=x1)
			j--;
		j++;
		if( i+j<=n && a[i+j].f*(n-i-j+1)>=x2){
		 	cout<<"Yes"<<endl;               
			cout<<j<<" "<<n-i-j+1<<endl;
			for(int q=i;q<i+j;q++)
				cout<<a[q].s<<" ";cout<<endl;
			for(int q=i+j;q<=n;q++)
				cout<<a[q].s<<" ";cout<<endl;
		   	return 0;
		}	
	}
	swap(x1,x2);
	for(int i=1,j=n;i<=n;i++){           
		while(a[i].f*j>=x1)
			j--;
		j++;
		if( i+j<=n && a[i+j].f*(n-i-j+1)>=x2){
		 	cout<<"Yes"<<endl;               
			cout<<n-i-j+1<<" "<<j<<endl;
			for(int q=i+j;q<=n;q++)
				cout<<a[q].s<<" ";cout<<endl;
		   	for(int q=i;q<i+j;q++)
				cout<<a[q].s<<" ";cout<<endl;
			return 0;
		}	
	}
	cout<<"No";
}