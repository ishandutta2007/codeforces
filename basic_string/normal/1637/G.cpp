#include<bits/stdc++.h>
using namespace std;
multiset<int>s,t;
void ins(int i){
		if((i&-i)==i)t.insert(i);
			else s.insert(i);
}
vector<pair<int,int>>v;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k,o;
	cin>>T;
	while(T--){
		cin>>n;
		if(n==2){
			cout<<-1<<'\n';
			continue;
		}
		s.clear(),t.clear();v={};
		for(i=1;i<=n;++i){
		ins(i);
		}
		o=2<<__lg(n-1);
		while(s.size()){
			vector<int>vec;
			while(s.size()){
				i=*s.rbegin(),s.erase(s.find(i));
			for(j=o;j;j>>=1){
				k=j-i;
				if(s.count(k)||t.count(k)){
					if(s.count(k))s.erase(s.find(k));
					else t.erase(t.find(k));
					vec.push_back(i+k);
					vec.push_back(abs(i-k));
					v.push_back({i,k});
					goto gg;
				}
			}
			cout<<-1<<'\n';goto gg2;
			throw;
			gg:;
			}
			for(int k:vec)ins(k);
		}
		for(j=o/2;j;j>>=1)if(t.count(j)>1){
			t.erase(t.find(j)),t.erase(t.find(j));
			ins(j*2);v.push_back({j,j});
			break;
		}
		for(int k:t)if(k<o){
			while(k<o)v.push_back({k,0}),v.push_back({k,k}),k*=2;
		}
		v.push_back({o,0});
		cout<<v.size()<<'\n';
		for(auto p:v)cout<<p.first<<' '<<p.second<<'\n';
		gg2:;
		
	}
	return 0;
}