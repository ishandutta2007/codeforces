#include<bits/stdc++.h>
#define N 100100
using namespace std;
int a[N];
int main(){
	int n,d,b;
	scanf("%d%d%d",&n,&d,&b);
	int r=(n+1)/2,l=-1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	while(l+1<r){
		int m=(l+r)/2;
		bool flag=true;
		int pre=0,cur=0;
		for(int j=m+1;j<=(n+1)/2;j++){
			while(pre<(j-m)*b) pre+=a[++cur];
			if(cur-j>1LL*j*d) flag=false;
		}
		pre=0,cur=n+1;
		for(int j=n-m;j>(n+1)/2;j--){
			while(pre<(n-m+1-j)*b) pre+=a[--cur];
			if(j-cur>1LL*(n-j+1)*d) flag=false;
		}
		if(flag) r=m;
		else l=m;
	}
	printf("%d\n",r);
	return 0;
}