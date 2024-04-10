#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int a[N],ct[N],b[N];
vector<int>v;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k,now,id=1;
	cin>>T;
	for(;T--;){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i],++ct[a[i]];
		v={};
		now=0;
		for(i=1;i<=n;++i){
			b[a[i]]=id;--ct[a[i]];
			while(b[now]==id)++now;
			if(!ct[now]){
				v.push_back(now);
				++id;now=0;
			}
		}
		cout<<v.size()<<'\n';
		for(auto o:v)cout<<o<<' ';cout<<'\n';
	}
	return 0;
}