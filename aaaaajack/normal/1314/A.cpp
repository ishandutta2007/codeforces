#include<bits/stdc++.h>
#define N 200100
using namespace std;
pair<int,int> p[N];
int main(){
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&p[i].first);
	}
	for(int j=0;j<n;j++){
		scanf("%d",&p[j].second);
	}
	sort(p,p+n);
	multiset<int> cst;
	long long ans=0,sum=0;
	cst.insert(p[0].second);
	sum+=p[0].second;
	for(int i=1;i<n;i++){
		int add=0;
		for(auto it=cst.end();it!=cst.begin()&&p[i-1].first+add<p[i].first;){
			--it;
			ans+=1LL*(*it)*add;
			sum-=*it;
			it=cst.erase(it);
			add++;
		}
		ans+=sum*add;
		cst.insert(p[i].second);
		sum+=p[i].second;
	}
	int add=0;
	for(auto it=cst.end();it!=cst.begin();){
		--it;
		ans+=1LL*(*it)*add;
		sum-=*it;
		it=cst.erase(it);
		add++;
	}
	printf("%lld\n",ans);
	return 0;
}