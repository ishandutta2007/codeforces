#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=200005;
int n,k;
LL sum;
LL a[maxn];
int s[maxn];
bool solve() {
	if(sum%k) return 0;
	int m=0;
	for(int i=1,j;i<=n;i=j+1) {
		LL cur=0;
		for(j=i;j<=n;j++) {
			cur+=a[j];
			if(cur>=sum/k) break;
		}
		if(cur!=sum/k) return 0;
		s[m++]=j-i+1;
	}
	return 1;
}
int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%lld",a+i);
		sum+=a[i];
	}
	if(solve()) {
		puts("Yes");
		for(int i=0;i<k;i++)
			printf("%d ",s[i]);
	} else 
		puts("No");
	return 0;
}