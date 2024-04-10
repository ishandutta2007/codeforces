#include<bits/stdc++.h>
#define N 500100
using namespace std;
vector<int> r[N],d[N];
bool cmp(const vector<int> &a,const vector<int>& b){
	for(int i=0;i<a.size();i++){
		if(a[i]<b[i]) return true;
		if(a[i]>b[i]) return false;
	}
	return false;
}
bool cid(int a,int b){
	return cmp(d[a],d[b]);
}
long long gcd(long long a, long long b){
	while(b){
		a%=b;
		swap(a,b);
	}
	return a;
}
long long vr[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		long long ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&vr[i]);
		int x,y;
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			d[y].push_back(x);
		}
		for(int i=1;i<=n;i++){
			sort(d[i].begin(),d[i].end());
			r[d[i].size()].push_back(i);
		}
		for(int i=1;i<=n;i++){
			//puts("sort start");
			sort(r[i].begin(),r[i].end(),cid);
			//puts("sort done");
			long long tmp=0;
			for(int j=0;j<r[i].size();j++){
				tmp+=vr[r[i][j]];
				if(j==r[i].size()-1 || cid(r[i][j],r[i][j+1])){
					ans=gcd(ans,tmp);
					tmp=0;
				}
			}
		}
		for(int i=0;i<=n;i++){
			r[i].clear();
			d[i].clear();
		}
		printf("%lld\n",ans);
	}
	return 0;
}