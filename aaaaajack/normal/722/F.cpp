#include<bits/stdc++.h>
#define N 100100
using namespace std;
vector<int> a[N],r[N];
int k[N];
vector<int> v[N];
long long gcd(long long a,long long b){
	while(b){
		a%=b;
		a^=b,b^=a,a^=b;
	}
	return a;
}
int main(){
	int n,m,x;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&k[i]);
		for(int j=0;j<k[i];j++){
			scanf("%d",&x);
			a[x].push_back(i);
			r[x].push_back(j);
			v[i].push_back(x);
		}
	}
	for(int i=1;i<=m;i++){
		int tmp=0;
		vector<pair<long long,pair<long long,int> > > pre,nxt;
		for(int j=0;j<a[i].size();j++){
			if(!j||a[i][j]!=a[i][j-1]+1) pre.clear();
			nxt.clear();
			for(auto it=pre.begin();it!=pre.end();++it){
				long long q=it->first,pr=it->second.first;
				long long g=gcd(q,k[a[i][j]]),mul=k[a[i][j]]/g;
				if(!nxt.empty()&&nxt.back().first==q*mul) continue;
				if(pr%g!=r[i][j]%g) continue;
				for(int l=0;l<mul;l++){
					if((l*q+pr)%k[a[i][j]]==r[i][j]){
						nxt.push_back(make_pair(q*mul,make_pair(l*q+pr,it->second.second+1)));
						break;
					}
				}
			}
			if(nxt.empty()||nxt.back().first!=k[a[i][j]]) nxt.push_back(make_pair(k[a[i][j]],make_pair(r[i][j],1)));
			pre=nxt;
			tmp=max(tmp,pre.front().second.second);
		}
		printf("%d\n",tmp);
	}
	return 0;
}