#include<cstdio>
using namespace std;
long long cnt[51];
int main(){
	int n,now=1;
	long long l;
	scanf("%d",&n);
	scanf("%I64d",&l);
	cnt[0]=1;
	cnt[1]=1;
	for(int i=2;i<51;i++) cnt[i]=cnt[i-1]+cnt[i-2];
	while(now<=n){
		if(l<=cnt[n-now]) printf("%d ",now),now++;
		else{
			l-=cnt[n-now];
			printf("%d %d ",now+1,now);
			now+=2;
		}
	}
	puts("");
	return 0;
}