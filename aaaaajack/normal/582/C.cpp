#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 200100
using namespace std;
int a[N];
int len[N*2],cop[N];
long long ans;
int gcd(int x,int y){
	while(y){
		x%=y;
		x^=y,y^=x,x^=y;
	}
	return x;
}
void add(int i,int n){
	if(i==n) return;
	memset(len,0,sizeof(len));
	for(int j=0;j<i;j++){
		int tmp=0;
		for(int k=0;k<n/i;k++){
			if(a[k*i+j]>tmp) tmp=a[k*i+j];
		}
		for(int k=0;k<n/i;k++){
			if(a[k*i+j]==tmp){
				len[k*i+j]=len[k*i+j+n]=1;
			}
		}
	}
	for(int j=n*2-2;j>=0;j--){
		if(len[j]){
			len[j]+=len[j+1];
			if(len[j]>n-1) len[j]=n-1;
		}
	}
	cop[0]=0;
	for(int j=1;j<n/i;j++){
		if(gcd(j,n/i)==1) cop[j]=cop[j-1]+1;
		else cop[j]=cop[j-1];
	}
	for(int j=0;j<n;j++){
		ans+=cop[len[j]/i];
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			add(i,n);
			if(n/i!=i) add(n/i,n);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}