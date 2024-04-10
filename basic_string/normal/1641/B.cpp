#include<bits/stdc++.h>
using namespace std;
enum{N=509};
int a[N],b[N];
map<int,int>mp;
vector<pair<int,int>>a1;
vector<int>a2;
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,i,t,j,o,k;
	for(cin>>T;T--;){
		cin>>n,a1={},a2={},mp={};
		for(i=1;i<=n;++i)cin>>a[i],++mp[a[i]];
		for(auto o:mp)if(o.second&1){cout<<"-1\n";goto gg;}
		for(i=t=o=0;i<2;++i)for(auto o:mp)for(j=o.second/2;j;--j)b[++t]=o.first;
		for(i=n;i;--i){
			for(j=i;;--j)if(a[j]==b[i])break;
			for(k=1;k<=j;++k)a1.push_back({k+o+j-1,a[k]});
			reverse(a+1,a+j+1),a2.push_back(j),o+=2*j;
			for(k=1;k<=i;++k)a1.push_back({k+o+i-1,a[k]});
			reverse(a+1,a+i+1),a2.push_back(i),o+=2*i;
		}
		a2.push_back(n/2);
		cout<<a1.size()<<'\n';
		for(auto o:a1)cout<<o.first<<' '<<o.second<<'\n';
		cout<<a2.size()<<'\n';
		for(auto o:a2)cout<<o*2<<' ';cout<<'\n';
		gg:;
	}
}