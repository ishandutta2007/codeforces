#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 5010
using namespace std;
int l[N*2],pos[N*2];
long long ans[N*2];
int dis(int n,int k){
	if(k>=l[n*2]) return k-l[n*2];
	else if(k<=l[n*2-1]) return l[n*2-1]-k;
	return 0;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&l[0]);
	for(int i=1;i<=n;i++) scanf("%d%d",&l[i*2-1],&l[i*2]);
	memcpy(pos,l,sizeof(l));
	sort(pos,pos+n*2+1);
	m=unique(pos,pos+n*2+1)-pos;
	for(int i=n;i>=1;i--){
		int tmp=lower_bound(pos,pos+m,l[i*2-1])-pos-1;
		for(int j=tmp;j>=0;j--){
			ans[j]=min(ans[j],ans[j+1]);
		}
		tmp=upper_bound(pos,pos+m,l[i*2])-pos;
		for(int j=tmp;j<m;j++){
			ans[j]=min(ans[j],ans[j-1]);
		}
		for(int j=0;j<m;j++){
			ans[j]+=dis(i,pos[j]);
		}
	}
	int tmp=lower_bound(pos,pos+m,l[0])-pos;
	printf("%I64d\n",ans[tmp]);
	return 0;
}