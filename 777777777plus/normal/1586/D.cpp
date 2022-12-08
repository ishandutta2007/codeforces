#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n;
int r[N],l[N];

int out(int t){
	printf("? ");
	for(int i=1;i<=n;++i)
	if(i==t)printf("2 ");
	else printf("1 ");
	printf("\n");
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}

int out1(int t){
	printf("? ");
	for(int i=1;i<=n;++i)
	if(i==t)printf("1 ");
	else printf("2 ");
	printf("\n");
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x=out(i);
		if(x!=i&&x){
			r[i]=x;
			l[x]=i;
		}
	}
	for(int i=1;i<=n;++i){
		int x=out1(i);
		if(x!=i&&x){
			l[i]=x;
			r[x]=i;
		}
	}
	static int a[N];
	for(int i=1;i<=n;++i)
	if(!l[i]){
		int c=0;
		for(int j=i;j;j=r[j]){
			a[j]=++c;
		}
	}
	printf("! ");
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	printf("\n");
	fflush(stdout);
}