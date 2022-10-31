#include<cstdio>
#define N 500100
using namespace std;
int a[N],b[N];
int main(){
	int n,cnt=0,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		if(i>0&&i<n-1&&a[i]!=a[i-1]&&a[i]!=a[i+1]) cnt++;
		else{
			if(cnt&1){
				for(int j=i-cnt;j<i;j++){
					b[j]=a[i];
				}
			}
			else{
				for(int j=i-cnt;j<i-cnt/2;j++){
					b[j]=a[i-cnt-1];
				}
				for(int j=i-cnt/2;j<i;j++){
					b[j]=a[i];
				}
			}
			b[i]=a[i];
			cnt=0;
		}
		if(cnt>ans) ans=cnt;
	}
	printf("%d\n",(ans+1)/2);
	for(int i=0;i<n;i++){
		printf("%d ",b[i]);
	}
	return 0;
}