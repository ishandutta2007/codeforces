#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	char s[n+1][m+2];
	for(int o=1;o<=n;o++) scanf("%s",s[o]+1);
	bool a[n+2][m+2],b[n+2][m+2];
	for(int o=0;o<=n+1;o++) for(int i=0;i<=m+1;i++) a[o][i]=b[o][i]=0;
	a[1][1]=b[n][m]=1;
	for(int o=1;o<=n;o++) for(int i=1;i<=m;i++) a[o][i]|=((a[o-1][i]||a[o][i-1])&&s[o][i]=='.');
    for(int o=n;o>=1;o--) for(int i=m;i>=1;i--) b[o][i]|=((b[o+1][i]||b[o][i+1])&&s[o][i]=='.');
    vector<int> v(n+m+1,0);
    for(int o=1;o<=n;o++) for(int i=1;i<=m;i++) if(a[o][i]&&b[o][i]) v[o+i]++;
    int res=2;
    for(int i=3;i<n+m;i++) res=min(res,v[i]);
    printf("%d\n",res);
	return 0;
}