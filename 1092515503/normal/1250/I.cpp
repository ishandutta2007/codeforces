#include<bits/stdc++.h>
using namespace std;
int n,x,y,p,a[50],res;
int f[2][1<<22];
void chmx(int&x,int y){if(x<y)x=y;}
int main(){
	scanf("%d%d%d",&n,&x,&y),p=x+y;
	if(x>y)swap(x,y);
	for(int i=0;i<p;i++)a[i]=n/p;
	for(int i=0;i<n%p;i++)a[i]++;
//	for(int i=0;i<p;i++)printf("%d ",a[i]);puts("");
	memset(f,0x80,sizeof(f));
	f[0][0]=0;
	for(int i=0;i<p;i++){
		memset(f[!(i&1)],0x80,sizeof(f[!(i&1)]));
		for(int j=0;j<(1<<y);j++){
			if(!(j&1)&&!(j&(1<<y-x)))
				chmx(f[!(i&1)][(j>>1)|(1<<y-1)],f[i&1][j]+a[i]);
			chmx(f[!(i&1)][j>>1],f[i&1][j]);
		}
	}
	for(int j=0;j<(1<<y);j++)chmx(res,f[p&1][j]);
	printf("%d\n",res);
	return 0;
}