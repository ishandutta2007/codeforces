#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int l,now=1,maxr=1,vec_t;
int z[100002],vec[100002],nx[100002],cnt[100002]={};
char s[100002];
inline bool cmp(int a,int b)
{
	return a>b? 1:0;
}
inline int min(int a,int b)
{
	return a<b? a:b;
}
int main()
{
	scanf("%s",s+1),++cnt[vec[vec_t=1]=l=strlen(s+1)],nx[0]=-1;
	for(int i=1,j;i<=l;++i)
	{
		for(j=nx[i-1];~j && s[j+1]!=s[i];j=nx[j]);
		nx[i]=j+1;
	}
	for(int i=2;i<=l;++i)
	{
		if(i<=maxr)z[i]=min(z[i-now+1],maxr-i+1);else z[i]=0;
		while(i+z[i]<=l && s[z[i]+1]==s[i+z[i]])++z[i];
		if(i+z[i]-1>maxr)maxr=i+z[i]-1,now=i;
		if(z[i] && !cnt[z[i]])vec[++vec_t]=z[i];++cnt[z[i]];
	}
	sort(vec+1,vec+vec_t+1,cmp);
	for(int i=1;i<vec_t;++i)cnt[vec[i+1]]+=cnt[vec[i]];
	vec_t=0;for(int i=l;i;i=nx[i])vec[++vec_t]=i;
	printf("%d\n",vec_t);
	for(int i=vec_t;i;--i)printf("%d %d\n",vec[i],cnt[vec[i]]);
	return 0;
}