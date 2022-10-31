#include<cstdio>
#include<algorithm>
#define N 100100
using namespace std;
int a[N]={0},l[N][3]={0},b[N];
int main(){
	int n,i,ans=1;
	scanf("%d",&n);
	l[1][0]=l[1][1]=l[1][2]=1;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			l[i][0]=l[i-1][0]+1;
		}
		else{
			l[i][0]=1;
		}
		b[i]=a[i-1]+1;
		l[i][1]=2;
		if(a[i]>b[i-1]){
			l[i][1]=max(l[i][1],l[i-1][2]+1);
		}
		if(a[i]>a[i-1]){
			l[i][1]=max(l[i][1],l[i-1][1]+1);
		}
		l[i][2]=l[i-1][0]+1;
		ans=max(l[i][1],ans);
		ans=max(l[i][2],ans);
		//printf("%d %d\n",l[i][0],l[i][1]);
	}
	printf("%d\n",ans);
	return 0;
}