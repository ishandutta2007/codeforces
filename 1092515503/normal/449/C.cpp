#include<bits/stdc++.h>
using namespace std;
int n,pri[100100];
void sieve(){
	for(int i=2;i<=(n>>1);i++){
		if(!pri[i])pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<=(n>>1);j++){
			pri[i*pri[j]]=true;
			if(!(i%pri[j]))break;
		}
	}
}
bool vis[100100];
vector<int>v;
vector<pair<int,int> >u;
int main(){
	scanf("%d",&n);
	sieve();
	for(int i=pri[0];i;i--){
		for(int j=pri[i];j<=n;j+=pri[i])if(!vis[j])v.push_back(j);
		if(v.size()&1)v.erase(v.begin()+1);
		for(int j=0;j<v.size();j+=2)u.emplace_back(v[j],v[j+1]),vis[v[j]]=true,vis[v[j+1]]=true;
		v.clear();
	}
	printf("%d\n",u.size());
	for(auto i:u)printf("%d %d\n",i.first,i.second);
	return 0;
}