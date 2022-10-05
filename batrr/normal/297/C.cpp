#include <bits/stdc++.h>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=5e5+123,inf=1e9+123,LOG=18,block=450,mod=1e9+7,N=5e5+123;
int n,a[maxn],b[maxn];
pair<int,int>x[maxn];
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
	#endif                                     
	cin>>n;
	for(int i=0 ; i<n ; i++){
    	cin>>x[i].f;
		x[i].s=i;
	}
	sort(x,x+n);
	for(int i=0 ; i<n/3 ; i++){
    	a[x[i].s]=i;
    	b[x[i].s]=x[i].f-i;
	}
	for(int i=n/3 ; i<2*n/3 ; i++){
   		b[x[i].s]=i;
    	a[x[i].s]=x[i].f-i;
	}
	for(int i=2*n/3 ; i<n ; i++){
    	b[x[i].s]=(n-1)-i;
    	a[x[i].s]=x[i].f-(n-1)+i;
	}
	cout<<"YES"<<endl;             
	for(int i=0 ; i<n ; i++) 
		cout<<a[i]<<" ";cout<<endl;
	for(int i=0 ; i<n ; i++) 
		cout<<b[i]<<" ";cout<<endl;
	return 0;
}