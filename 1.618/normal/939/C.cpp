#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
int n,a[200005],s,f,sum[200005];
int maxsum = 0,maxst;
int mo(int x){
	while(x < 1) x += n/2;
	while(x > n/2) x -= n/2;
	return x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=n+1;i<=(n<<1);i++) a[i] = a[i-n];
	n <<= 1;
	scanf("%d%d",&s,&f);
	for(int i=1;i<=n;i++) sum[i] = sum[i-1] + a[i];
	int d = f - s;
	for(int i=d;i<=n;i++){
		if(sum[i] - sum[i - d] > maxsum){
			maxsum = sum[i] - sum[i - d];
			maxst = mo(i - d + 1);
		}else if(sum[i] - sum[i - d] == maxsum && mo(s-(mo(i - d + 1)-1)) < mo(s-(maxst-1))){
			maxst = mo(i - d + 1);
		}
	}
	printf("%d\n",mo(s-(maxst-1)));
	return 0;
}