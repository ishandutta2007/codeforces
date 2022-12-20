#include <cstdio>

int n;
int ca[100000],cb[100000];
int a[100000],b[100000];
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d%d",a+i,b+i);
	int l=0,r=0;
	int cnt=0;
	while(cnt++<n) {
		if(a[l]<b[r]) {
			ca[l++]=1;
		}
		else cb[r++]=1;
	}
	for(int i=0;i<n/2;i++) ca[i]=cb[i]=1;
	for(int i=0;i<n;i++)printf("%d",ca[i]);
	puts("");
	for(int i=0;i<n;i++)printf("%d",cb[i]);
	return 0;
}