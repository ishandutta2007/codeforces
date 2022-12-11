#include<bits/stdc++.h>
#define int long long
#define N 200000
using namespace std;
int n,a[N+1],Q,n1,n0,p,q;
signed main(){
	cin>>n>>Q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i])n1++;
	}
	for(int i=1;i<=Q;i++){
		cin>>p>>q;
		if(p==1){
			if(a[q])n1--;else n1++;
			a[q]^=1;
		}else{
			if(n1>=q)cout<<1<<'\n';
			else cout<<0<<'\n';
		}
	}
	return 0;
}
/*

*/