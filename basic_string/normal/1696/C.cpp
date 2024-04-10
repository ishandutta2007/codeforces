#include<bits/stdc++.h>
using namespace std;
int a[100009],b[100009];
vector<pair<int,int>>va,vb;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,k,l;
	for(cin>>T;T--;){
		cin>>n>>m;va=vb={};
		
		for(i=1;i<=n;++i){
			cin>>j;l=1;
			while(j%m==0)j/=m,l*=m;
			va.push_back({j,l});
		}
		cin>>k;
		for(i=1;i<=k;++i){
			cin>>j;l=1;
			while(j%m==0)j/=m,l*=m;
			vb.push_back({j,l});
		}
	//	for(auto o:va)cout<<o.first<<' '<<o.second<<'!';cout<<'\n';
	//	for(auto o:vb)cout<<o.first<<' '<<o.second<<'!';cout<<'\n';
		while(va.size()||vb.size()){
			if(va.empty()||vb.empty()){cout<<"No\n";goto gg;}
			if(va.back().first!=vb.back().first){
				cout<<"No\n";goto gg;
			}
			if(va.back().second<vb.back().second){
				vb.back().second-=va.back().second;
				va.pop_back();
			}else{
				va.back().second-=vb.back().second;
				vb.pop_back();
				if(!va.back().second)va.pop_back();
			}
		}
		cout<<"Yes\n";
		gg:;
	}
}