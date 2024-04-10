#include<cstdio>
#define N 201000
#define S 450
using namespace std;
int a[N],m[N],cnt[N];
bool w[N][S];
int main(){
	int n,i,j,sq=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	while(sq*sq<n) sq++;
	sq+=5;
	for(i=1;i<n;i++){
		for(j=1;j<=sq;j++){
			if(a[i]<a[(i-1)/j]) m[j]++;
		}
	}
	for(i=1;i<n;i++){
		for(j=0;j<sq;j++){
			if(a[i]<a[j]){
				if(j) cnt[(i-1)/j]++;
				else cnt[n-1]++;
				cnt[(i-1)/(j+1)]--;
			}
		}
	}
	for(i=n-2;i>=0;i--){
		cnt[i]+=cnt[i+1];
	}
	for(i=1;i<n;i++){
		if(i>1) putchar(' ');
		if(i<=sq) printf("%d",m[i]);
		else printf("%d",cnt[i]);
	}
	putchar('\n');
	return 0;
}