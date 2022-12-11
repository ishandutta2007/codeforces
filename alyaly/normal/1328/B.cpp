#include<bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
int T,n,m,g[100001];
string s;
signed main(){
	cin>>T;
	for(int i=1;i<=100000;i++) g[i]=i*(i+1)/2;
	for(int i=1;i<=T;i++){
		cin>>n>>m;
		int np=lower_bound(g+1,g+100001,m)-g;
		for(int ii=1;ii<=n;ii++) s+='a';
		s[n-(np+1)]=s[n-(m-np*(np-1)/2)]='b';
		cout<<s<<'\n';
		s.clear();
	}
	return 0;
}