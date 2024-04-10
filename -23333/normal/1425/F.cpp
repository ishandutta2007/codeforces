#include<bits/stdc++.h>

#define LL long long
using namespace std;
const int N=2e3+10;
const LL mod=1e9+7;
int n;
int a[N];
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d",&n);
	//fflush(stdout);
	int x,y,z;
	printf("? %d %d\n",1,3);fflush(stdout);
	scanf("%d",&x);
	printf("? %d %d\n",2,3);fflush(stdout);
	scanf("%d",&y);
	printf("? %d %d\n",1,2);fflush(stdout);
	scanf("%d",&z);
	a[1]=x-y;
	a[2]=z-a[1];
	a[3]=y-a[2];
	for(int i=4;i<=n;++i){
		printf("? %d %d\n",i-1,i);fflush(stdout);
		scanf("%d",&x);
		a[i]=x-a[i-1];
	}
	printf("!");
	for(int i=1;i<=n;++i) printf(" %d",a[i]);
	puts("");fflush(stdout);
	return 0; 
}