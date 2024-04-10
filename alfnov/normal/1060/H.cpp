#include<bits/stdc++.h>
using namespace std;
int d,mod;
int C[105][105];
int a[105][105],h[105];
int powdv(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return ans;
}
int niyuan(int x){
	return powdv(x,mod-2);
}
void mutip(int a,int b,int x){
	x=(x%mod+mod)%mod;
	if(x==1){
		mutip(a,2107,(mod+1)/2);
		mutip(2107,b,2);
		return;
	}
	if(x==0)x+=mod;
	int fl=0;
	if(x&2)printf("+ %d %d %d\n",a,a,b),fl=1;
	printf("+ %d %d %d\n",a,a,1919);
	for(int i=2;i<=30;++i){
		if(x&(1<<i)){
			if(!fl){
				printf("+ %d %d %d\n",1919,1919,b);
				printf("+ %d %d %d\n",1919,1919,1919);
				fl=1;
			}else{
				printf("+ %d %d %d\n",1919,1919,1919);
				printf("+ %d %d %d\n",1919,b,b);
			}
		}else{
			printf("+ %d %d %d\n",1919,1919,1919);
		}
	}
	if(x&1)printf("+ %d %d %d\n",a,b,b);
}
void squr(int a,int b){
	mutip(666,b,0);
	for(int i=0;i<=d;++i){
		printf("+ %d %d %d\n",5000-i,a,810);
		printf("^ %d %d\n",810,888);
		mutip(888,514,h[i]);
		printf("+ %d %d %d\n",514,b,b);
	}
}
int main(){
	cin>>d>>mod;
	for(int i=0;i<=d;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
	for(int i=0;i<=d;++i){
		int bs=1;
		for(int j=0;j<=d;++j){
			a[d-j][i]=1ll*C[d][j]*bs%mod;
			bs=1ll*bs*i%mod;
		}
	}
	for(int j=0;j<=d;++j){
		if(j==2)a[j][d+1]=1;
		else a[j][d+1]=0;
	}
	for(int i=0;i<=d;++i){
		if(!a[i][i]){
			for(int j=i+1;j<=d;++j)if(a[j][i]){
				for(int k=0;k<=d+1;++k)swap(a[i][k],a[j][k]);
				break;
			}
		}
		if(!a[i][i])continue;
		int xx=niyuan(a[i][i]);
		for(int j=0;j<=d+1;++j)a[i][j]=1ll*a[i][j]*xx%mod;
		for(int j=0;j<=d;++j)if(i!=j){
			int tt=a[j][i];
			for(int k=0;k<=d+1;++k){
				a[j][k]=(a[j][k]-1ll*tt*a[i][k])%mod;
			}
		}
	}
	for(int i=0;i<=d;++i)h[i]=(a[i][d+1]+mod)%mod;
	mutip(666,5000,0);
	for(int i=4999;i>=5000-d;--i)printf("+ %d %d %d\n",i+1,666,i);
	printf("+ %d %d %d\n",1,2,10);
	squr(1,7);
	squr(2,8);
	squr(10,9);
	mutip(7,6,mod-1);
	mutip(8,5,mod-1);
	printf("+ %d %d %d\n",5,6,11);
	printf("+ %d %d %d\n",9,11,4);
	mutip(4,3,(mod+1)/2);
	printf("f %d\n",3);
	return 0;
}