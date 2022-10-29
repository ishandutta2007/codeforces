#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=20000010;
int n,m,g,r,i,j,d[11005],q1[N],q2[N],bg,ed,f[11005][1105];
long long ans=1ll<<60;
bool v[11005][1105];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
		scanf("%d",d+i);
	scanf("%d%d",&g,&r);
	sort(d+1,d+1+m);
	bg=ed=10000005;
	q1[bg]=1,q2[bg]=0;
	v[1][0]=true;
	while(bg<=ed)
	{
		i=q1[bg],j=q2[bg];
		++bg;
		if(j==g&&!v[i][0])
		{
			++ed;
			q1[ed]=i,q2[ed]=0;
			f[q1[ed]][q2[ed]]=f[i][j]+1;
			v[q1[ed]][q2[ed]]=true;
		}
		if(i<m&&j+d[i+1]-d[i]<=g&&!v[i+1][j+d[i+1]-d[i]])
		{
			--bg;
			q1[bg]=i+1,q2[bg]=j+d[i+1]-d[i];
			f[q1[bg]][q2[bg]]=f[i][j];
			v[q1[bg]][q2[bg]]=true;
		}
		if(i>1&&j+d[i]-d[i-1]<=g&&!v[i-1][j+d[i]-d[i-1]])
		{
			--bg;
			q1[bg]=i-1,q2[bg]=j+d[i]-d[i-1];
			f[q1[bg]][q2[bg]]=f[i][j];
			v[q1[bg]][q2[bg]]=true;
		}
	}
	for(i=1;i<m;++i)
		if(d[m]-d[i]<=g&&v[i][0])
			ans=min(ans,1ll*f[i][0]*(g+r)+d[m]-d[i]);
	if(ans==(1ll<<60))
		printf("-1");
	else
		printf("%lld",ans);
	return 0;
}