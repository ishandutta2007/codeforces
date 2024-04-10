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
ll n,mx,id;
pair< pair<int,int> ,int>a[maxn];
int main(){               
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].f.f>>a[i].f.s;
		a[i].f.s=-a[i].f.s;
		a[i].s=i;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		a[i].f.s=-a[i].f.s;
		if(mx>=a[i].f.s){
			cout<<a[i].s<<" "<<id;
			return 0;
		}
		if(mx<a[i].f.s)
			mx=a[i].f.s,id=a[i].s;
	}
	cout<<-1<<" "<<-1;
}