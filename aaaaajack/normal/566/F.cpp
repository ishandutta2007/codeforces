#include<cstdio>
#include<algorithm>
#define N 1001000
using namespace std;
int len[N],a[N],cnt[N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
	for(int i=1;i<N;i++) len[i]=cnt[i];
	for(int i=1;i<N;i++){
		for(int j=i*2;j<N;j+=i){
			len[j]=max(len[j],len[i]+cnt[j]);
		}
	}
	int ans=0;
	for(int i=1;i<N;i++) if(len[i]>ans) ans=len[i];
	printf("%d\n",ans);
	return 0;
}