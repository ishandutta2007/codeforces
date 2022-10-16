/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

const int N=1e3+5;

int t,n,k,c[N],ind[N];
string s;

int query(int l,int r){
	cout<<"? "<<r-l+1<<" ";
	for(int i=l;i<=r;i++)cout<<i<<" ";
	cout<<endl;
	int ans; cin>>ans; return ans;
}

int main(){
	cin>>t;
	while(t--){
		cin>>n>>k; mem(ind,0);
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=0,d;j<c[i];j++)cin>>d,ind[d]=i;
		} // input
		
		int l=1,r=n,mx=query(1,n);
		while(l<r){
			int m=l+r>>1;
			if(query(l,m)==mx)r=m;
			else l=m+1;
		} // query index
		
		cout<<"? "<<n-c[ind[l]]<<" ";
		for(int i=1;i<=n;i++)if(ind[i]!=ind[l]||!ind[l])cout<<i<<" ";
		cout<<endl; // query notin S_mx
		
		int ans; cin>>ans; cout<<"! ";
		for(int i=1;i<=k;i++)cout<<(i==ind[l]?ans:mx)<<" ";
		cout<<endl; cin>>s;
	}
	return 0;
}