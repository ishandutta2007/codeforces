#include<bits/stdc++.h>
std::bitset<4004>M[2004];
int n,m,x[1111111],y[1111111];
int main()
{
	scanf("%d%d",&n,&m);
	register int i,ii;
	for(i=1;i<=m;i++)scanf("%d%d",x+i,y+i),M[x[i]][y[i]]=1;
	for(i=1;i<=n;i++)M[i][i+n]=1;
	for(i=1;i<=n;i++)
	{
		if(!M[i][i])for(ii=i+1;ii<=n;ii++)
			if(M[ii][i]){M[0]=M[ii],M[ii]=M[i],M[i]=M[0];goto G;}
		G:for(ii=i+1;ii<=n;ii++)if(M[ii][i])M[ii]^=M[i];
	}for(i=n;i;i--)for(ii=n;ii>i;ii--)if(M[i][ii])M[i]^=M[ii];
	for(i=1;i<=m;i++)puts(M[y[i]][x[i]+n]?"NO":"YES");
}
/*
Please don't let me down.
*/