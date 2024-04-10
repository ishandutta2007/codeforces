#include<bits/stdc++.h>
#define N 200100
#define all(x) begin(x),end(x)
using namespace std;
typedef unsigned long long ull;
vector<ull> g[N];
bool con[1010][1010];
ull ch2(int n){
	return 1ull*n*(n-1)/2;
}
bool in(int i,int j){
	return binary_search(all(g[i]),j);
}
int main(){
	int n,m;
	ull a,b,c,x,y;
	ull ans=0;
	vector<tuple<int,int,int>> tri;
	scanf("%d%d%llu%llu%llu",&n,&m,&a,&b,&c);
	for(int i=0;i<n;i++){
		ans+=a*ch2(n-1-i)*i;
		ans+=c*ch2(i)*i;
		ans+=b*i*(n-1-i)*i;
	}
	for(int i=0;i<m;i++){
		scanf("%llu%llu",&x,&y);
		if(x>y) swap(x,y);
		g[x].push_back(y);
		g[y].push_back(x);
		ans-=x*(b*x+c*y)+a*((x-1)*x/2);
		ans-=(y-x-1)*(a*x+c*y)+b*((x+y)*(y-x-1)/2);
		ans-=(n-1-y)*(a*x+b*y)+c*((n+y)*(n-1-y)/2);
	}
	for(int i=0;i<n;i++){
		sort(all(g[i]));
		ull lc=0,rc=0;
		ull ls=0,rs=0;
		for(auto t:g[i]){
			if(t<i){
				ans+=ls*a+lc*b*t+lc*i*c;
				lc++,ls+=t;
			}
			else{
				ans+=rc*i*a+rs*b+rc*c*t;
				rc++,rs+=t;
			}
		}
		ans+=b*lc*rc*i+a*ls*rc+c*lc*rs;
	}
	vector<int> big;
	for(int i=0;i<n;i++){
		if(g[i].size()>400){
			big.push_back(i);
			continue;
		}
		for(int j=0;j<g[i].size();j++){
			int sj=g[i][j];
			if(g[sj].size()<=400 && sj<i) continue;
			for(int k=j+1;k<g[i].size();k++){
				int sk=g[i][k];
				if(g[sk].size()<=400 && sk<i) continue;
				if(!in(sj,sk)) continue;
				int t[3]={i,sj,sk};
				sort(t,t+3);
				ans-=a*t[0]+b*t[1]+c*t[2];
			}
		}
	}
	for(int i=0;i<big.size();i++){
		for(int j=i+1;j<big.size();j++){
			if(in(big[i],big[j])) con[i][j]=true;
		}
	}
	for(int i=0;i<big.size();i++){
		for(int j=i+1;j<big.size();j++){
			for(int k=j+1;k<big.size();k++){
				if(con[i][j]&&con[j][k]&&con[i][k]) ans-=a*big[i]+b*big[j]+c*big[k];
			}
		}
	}
	printf("%llu\n",ans);
	return 0;
}