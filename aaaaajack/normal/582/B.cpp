#define M 310
#define N 110
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[N*M],b[N*M];
int cnt[M];
int main(){
	int n,t,sz,mx=0,len=0;
	scanf("%d%d",&n,&t);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for(int i=0;i<M;i++){
		if(cnt[i]>mx) mx=cnt[i];
	}
	for(int j=1;j<M&&j<t;j++){
		memcpy(a+j*n,a,sizeof(int)*n);
	}
	sz=n*min(t,M);
	for(int i=0;i<sz;i++){
		int pos=upper_bound(b,b+len,a[i])-b;
		if(pos==len) len++;
		b[pos++]=a[i];
	}
	printf("%d\n",len+mx*max(0,t-M));
	return 0;
}