#include<bits/stdc++.h>
using namespace std;
int a[100005],d[405][100005];
int main()
{
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int S=max(1.0,sqrt(n/1.6));
	for(int i=1;i<=S;i++)for(int j=n;j>=1;j--)
		d[i][j]=d[i][min(n+1,j+a[j]+i)]+1;
	cin>>q;
	while(q--)
	{
		int p,k;
		scanf("%d%d",&p,&k);
		if(k<=S)printf("%d\n",d[k][p]);
		else
		{
			int cnt=0;
			while(p<=n)p+=a[p]+k,cnt++;
			printf("%d\n",cnt);
		}
	}
	return 0;
}