#include<bits/stdc++.h>

const int N=400005;

int n,a[N],bin[30],id[N],tmp[N],s[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	bin[0]=1;
	for (int i=1;i<=30;i++) bin[i]=bin[i-1]*2;
	int tot=0;
	for (int i=1;i<=n;i++)
		if (!(a[i]&bin[0])) id[++tot]=i;
	int ans=(tot%2)*((n-tot)%2)%2;
	for (int i=1;i<=n;i++)
		if (a[i]&bin[0]) id[++tot]=i;
	for (int i=1;i<27;i++)
	{
		for (int j=1;j<=n;j++)
			s[j]=s[j-1]+((a[id[j]]&bin[i])>0);
		int p=n+1,flag=0;
		for (int j=1;j<=n;j++)
		{
			while (p>1&&(a[id[j]]%bin[i]+a[id[p-1]]%bin[i])>=bin[i]) p--;
			int k=std::min(j,p);
			if (a[id[j]]&bin[i]) flag^=(s[j-1]-s[k-1])%2,flag^=(k-1-s[k-1])%2;
			else flag^=(j-k-s[j-1]+s[k-1])%2,flag^=s[k-1]%2;
		}
		if (flag) ans+=bin[i];
		tot=0;
		for (int j=1;j<=n;j++)
			if (!(a[id[j]]&bin[i])) tmp[++tot]=id[j];
		for (int j=1;j<=n;j++)
			if (a[id[j]]&bin[i]) tmp[++tot]=id[j];
		for (int j=1;j<=n;j++) id[j]=tmp[j];
	}
	printf("%d\n",ans);
	return 0;
}