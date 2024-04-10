#include<cstdio>
#define N 1001000
using namespace std;
int cnt[N];
int main(){
	int ans=0;
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		cnt[x]++;
	}
	for(int i=0;i<N-1;i++){
		if(cnt[i]&1) ans++;
		cnt[i+1]+=cnt[i]>>1;
	}
	printf("%d\n",ans);
	return 0;
}