#include<bits/stdc++.h>
int n,k;
int ans;
int e[1<<10][1<<10];
void solve(int L,int R,int D)
{
	//printf("[%d,%d]-%d\n",L,R,D);
	if(L>=R)return;
	if(ans<D)ans=D;
	int Ls=L;
	for(register int i=1;i<=k;i++)
	{
		int Rs=(L*(k-i)+R*i)/k;
		solve(Ls,Rs,D+1);
		Ls=Rs+1;
	}
	for(register int i=L;i<=R;i++)
		for(register int ii=i+1;ii<=R;ii++)
			if(!e[i][ii])e[i][ii]=D;
}
int main()
{
	scanf("%d%d",&n,&k);
	solve(1,n,1);
	printf("%d\n",ans);
	for(register int i=1,ii;i<=n;i++,puts(""))
		for(ii=i+1;ii<=n;ii++)
			printf("%d ",e[i][ii]);
}