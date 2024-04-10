#include<bits/stdc++.h>
using namespace std;
int T,n,a[1010],cnt[1010];
vector<int>v;
int MEX(){
	int j=0;
	while(cnt[j])j++;
	return j;
}
void FUNC(int i){
	int j=MEX();
	cnt[a[i]]--;
	a[i]=j;
	cnt[j]++;
	v.push_back(i);
}
bool che(){
	for(int i=2;i<=n;i++)if(a[i-1]>a[i])return false;
	return true;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),v.clear(),a[n+1]=n;
		for(int i=0;i<=n;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++;
		for(int i=1;i<=n;i++){
			if(cnt[a[i]]==1)continue;
			FUNC(i);
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=n)continue;
			FUNC(i);
		}
//		for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
//		for(auto i:v)printf("%d ",i);puts("");
		while(!che()){
			int i=MEX();
			if(a[i+1]==i){
				int j=n;
				for(;a[j]==j-1;j--);
				FUNC(j);
			}else FUNC(i+1);
		}
//		for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
		printf("%d\n",v.size());
		for(auto i:v)printf("%d ",i);puts("");
	}
	return 0;
}
/*
1
6
5 4 3 2 1 0
*/