#include<bits/stdc++.h>
#define N 100100
using namespace std;
int sa[N],sb[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&sa[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&sb[i]);
		}
		sort(sa+1,sa+n+1);
		sort(sb+1,sb+n+1);
		for(int i=1;i<=n;i++){
			sa[i]+=sa[i-1];
			sb[i]+=sb[i-1];
		}
		int l=-1,r=n;
		while(l+1<r){
			int m=(l+r)/2;
			int d=(n+m)/4;
			if(sa[n]-sa[d]+m*100>=sb[n]-sb[max(d-m,0)]) r=m;
			else l=m;
		}
		printf("%d\n",r);
	}
	return 0;
}