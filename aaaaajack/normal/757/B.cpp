#include<bits/stdc++.h>
#define N 100100
using namespace std;
int a[N],cnt[N];
int main(){
	int n,ans=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		for(int j=1;j*j<=a[i];j++){
			if(a[i]%j==0){
				cnt[j]++;
				if(a[i]/j!=j) cnt[a[i]/j]++;
			}
		}
	}
	for(int i=2;i<N;i++){
		ans=max(ans,cnt[i]);
	}
	printf("%d\n",ans);
	return 0;
}