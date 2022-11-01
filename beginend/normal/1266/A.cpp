#include<bits/stdc++.h>

int n,m,a[15];
char str[105];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",str);
		m=strlen(str);
		memset(a,0,sizeof(a));
		for (int j=0;j<m;j++) a[str[j]-'0']++;
		if (!a[0]) {puts("cyan");continue;}
		a[0]--;
		int s1=0,s2=0;
		for (int j=0;j<9;j+=2) s1+=a[j];
		for (int j=0;j<=9;j++) s2+=j*a[j];
		if (s2%3==0&&s1) puts("red");
		else puts("cyan");
	}
	return 0;
}