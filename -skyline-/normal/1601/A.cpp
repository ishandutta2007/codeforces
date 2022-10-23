#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,a[200005],cnt[35];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<30;++i)cnt[i]=0;
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
			for(int j=0;j<30;++j)if(a[i]&(1<<j))++cnt[j];
		}
		int k=0;
		for(int i=0;i<30;++i){
			if(cnt[i]){
				if(k)k=__gcd(k,cnt[i]);
				else k=cnt[i];
			}
		}
		if(k==0){
			for(int i=1;i<n;++i)printf("%d ",i);
			printf("%d\n",n);
			continue;
		}
		for(int i=1;i<k;++i)if(k%i==0)printf("%d ",i);
		printf("%d\n",k);
	}
    return 0;
}