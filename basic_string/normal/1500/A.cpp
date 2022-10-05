#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int a[N];
basic_string<int>b[2500009]; 
pair<int,int>p[5000009];
map<int,int>mp;
int main(){
	int T,n,i,j=0,k=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i),b[a[i]]+=i;
	for(i=0;i<2500009;++i)if(b[i].size()>1){
		if(j)k=i;
		else j=i;
	}
	if(k){
		puts("YES");
		printf("%d %d %d %d",b[j][0],b[k][0],b[j][1],b[k][1]);
		return 0;
	}
	for(i=0;i<2500009;++i)if(b[i].size()>3){
		puts("YES");
		printf("%d %d %d %d",b[i][0],b[i][1],b[i][2],b[i][3]);
		return 0;
	}
	if(j){
		for(i=1;i<=n;++i)if(a[i]!=j)mp[j+j-a[i]]=1;
		for(i=1;i<=n;++i)if(a[i]!=j&&mp[a[i]]){
			puts("YES");
			printf("%d %d %d %d",b[j][0],b[j][1],b[a[i]][0],b[j+j-a[i]][0]);
			return 0;
		}
	}
	sort(a+1,a+n+1),n=unique(a+1,a+n+1)-a-1;
	for(i=1;i<=n;++i)for(j=1;j<i;++j){
		k=a[i]+a[j];
		if(p[k]!=make_pair(0,0)){
			puts("YES");
			printf("%d %d %d %d",b[p[k].first][0],b[p[k].second][0],b[a[i]][0],b[a[j]][0]);
			return 0;
		}
		p[k]={a[i],a[j]};
	}
	puts("NO");
	return 0;
}