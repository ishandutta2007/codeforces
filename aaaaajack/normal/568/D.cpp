#include<cstdio>
#include<random>
#define N 100100
using namespace std;
long long a[N],b[N],c[N];
pair<int,int> ans[5];
int check(const vector<int>& v,int k){
	if(v.empty()) return k;
	if(k==0) return -1;
	if(v.size()==1){
		ans[k-1]=make_pair(v[0]+1,-1);
		return k-1;
	}
	if(v.size()<=k*k){
		for(int i=1;i<v.size();i++){
			vector<int> tmp;
			ans[k-1]=make_pair(v[0]+1,v[i]+1);
			long long tx=b[v[0]]*c[v[i]]-b[v[i]]*c[v[0]];
			long long ty=c[v[0]]*a[v[i]]-c[v[i]]*a[v[0]];
			long long tz=a[v[0]]*b[v[i]]-a[v[i]]*b[v[0]];
			if(tz==0) continue;
			for(int j=1;j<v.size();j++){
				if(j==i) continue;
				if(tx*a[v[j]]+ty*b[v[j]]+tz*c[v[j]]!=0) tmp.push_back(v[j]);
			}
			int res=check(tmp,k-1);
			if(res>=0) return res;
		}
		return -1;
	}
	ranlux24 rng;
	vector<int> tmp[2];
	int mx=0;
	tmp[mx]=v;
	for(int T=0;T<200;T++){
		int p1=rng()%v.size(),p2=rng()%v.size();
		if(p1==p2) continue;
		long long tx=b[v[p1]]*c[v[p2]]-b[v[p2]]*c[v[p1]];
		long long ty=c[v[p1]]*a[v[p2]]-c[v[p2]]*a[v[p1]];
		long long tz=a[v[p1]]*b[v[p2]]-a[v[p2]]*b[v[p1]];
		if(tz==0) continue;
		for(int j=0;j<v.size();j++){
			if(j==p1||j==p2) continue;
			if(tx*a[v[j]]+ty*b[v[j]]+tz*c[v[j]]!=0) tmp[mx^1].push_back(v[j]);
		}
		if(tmp[mx^1].size()<tmp[mx].size()){
			mx^=1;
			ans[k-1]=make_pair(v[p1]+1,v[p2]+1);
		}
		tmp[mx^1].clear();
	}
	if((v.size()-tmp[mx].size())*k<v.size()) return -1;
	return check(tmp[mx],k-1);
}
int main(){
	int n,k,res;
	vector<int> v;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%I64d%I64d%I64d",&a[i],&b[i],&c[i]),v.push_back(i);
	res=check(v,k);
	if(res>=0){
		puts("YES");
		printf("%d\n",k-res);
		for(int i=res;i<k;i++) printf("%d %d\n",ans[i].first,ans[i].second);
	}
	else puts("NO");
	return 0;
}