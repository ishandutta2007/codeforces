#include<bits/stdc++.h>
using namespace std;
int n,N,q,t,cnt,lt,ut,lut,A,B,C;
int mx[2250002],pre[1502];
int a[1502][1502];
int L[1502][1502][13],U[1502][1502][13],LU[1502][1502][13],LUcol[1502][1502][13];
int main()
{
	scanf("%d%d",&n,&q),N=n*n,++q;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)scanf("%d",&a[i][j]);
		for(int k=1;k<=q;++k)
		{
			t=1,cnt=0;
			for(int j=1;j<=n;++j)
			{
				for(cnt+=(!mx[a[i][j]]),mx[a[i][j]]=j;cnt>=k;++t)if(mx[a[i][t]]==t)--cnt,mx[a[i][t]]=0;
				L[i][j][k]=t-1;
			}
			for(int j=1;j<=n;++j)mx[a[i][j]]=0;
		}
	}
	for(int i=1;i<=n;++i)
		for(int k=1;k<=q;++k)
		{
			t=1,cnt=0;
			for(int j=1;j<=n;++j)
			{
				for(cnt+=(!mx[a[j][i]]),mx[a[j][i]]=j;cnt>=k;++t)if(mx[a[t][i]]==t)--cnt,mx[a[t][i]]=0;
				U[j][i][k]=t-1;
			}
			for(int j=1;j<=n;++j)mx[a[j][i]]=0;
		}
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
		{
			LU[i][j][0]=-1;
			for(int k=1;k<=q+1;++k)LU[i][j][k]=n+1;
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			lt=ut=lut=mx[a[i][j]]=1,LU[i][j][1]=0,LUcol[i][j][1]=a[i][j];
			for(int k=2;k<=q;)
			{
				A=L[i][j][lt]? j-L[i][j][lt]:n+1,B=U[i][j][ut]? i-U[i][j][ut]:n+1,C=LU[i-1][j-1][lut]<=n? LU[i-1][j-1][lut]+1:n+1;
				if(A<=n && A<=B && A<=C)
				{
					if(A<min(i,j) && !mx[a[i][j-A]])mx[a[i][j-A]]=1,LU[i][j][k]=A,LUcol[i][j][k]=a[i][j-A],++k;
					++lt;
				}
				else if(B<=n && B<=A && B<=C)
				{
					if(B<min(i,j) && !mx[a[i-B][j]])mx[a[i-B][j]]=1,LU[i][j][k]=B,LUcol[i][j][k]=a[i-B][j],++k;
					++ut;
				}
				else if(C<=n)
				{
					if(!mx[LUcol[i-1][j-1][lut]])mx[LUcol[i-1][j-1][lut]]=1,LU[i][j][k]=C,LUcol[i][j][k]=LUcol[i-1][j-1][lut],++k;
					++lut;
				}
				else break;
			}
			for(int k=1;k<=q;++k)mx[LUcol[i][j][k]]=0;
			mx[a[i][j]]=0,++pre[min(LU[i][j][q]-1,min(i,j)-1)];
		}
	for(int i=n;i;--i)pre[i-1]+=pre[i];
	for(int i=0;i<n;++i)printf("%d\n",pre[i]);
	return 0;
}