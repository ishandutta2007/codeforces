#include<stdio.h>
int T,i,j,k,w[60][6],t,t2,l,n;
bool v[60];
char p[20];
long long D[20][10][6];
bool vv[20][10];
int main()
{
	for(i=0;i<=6;i++){
		for(j=0;j<=6-i;j++){
			t=6-i-j;
			t2=j*4+t*7;
			for(k=0;k<i;k++)w[t2][k]=0;
			for(k=i;k<i+j;k++)w[t2][k]=4;
			for(k=i+j;k<6;k++)w[t2][k]=7;
			v[t2]=true;
		}
	}
	scanf("%d",&T);
	while(T--){
		scanf("%s",p);
		for(i=0;i<=p[0]-'0';i++){
			if(v[i]){
				vv[0][p[0]-'0'-i]=true;
				for(j=0;j<6;j++){
					D[0][p[0]-'0'-i][j]=w[i][j];
				}
			}
		}
		for(i=1;p[i];i++){
			for(j=0;j<=42;j++){
				if(!v[j])continue;
				for(k=0;k<10;k++){
					if(!vv[i-1][k])continue;
					t=k*10+p[i]-'0'-j;
					if(t>=10 || t<0)continue;
					vv[i][t]=true;
					for(l=0;l<6;l++){
						D[i][t][l]=D[i-1][k][l]*10LL+w[j][l];
					}
				}
			}
		}
		n=i;
		if(!vv[n-1][0])printf("-1\n");
		else{
			for(i=0;i<6;i++){
				printf("%lld ",D[n-1][0][i]);
			}
			printf("\n");
		}
		for(i=0;i<n;i++)for(j=0;j<9;j++)vv[i][j]=false;
	}
}