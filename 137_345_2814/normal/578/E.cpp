#include<cstdio>
#include<set>
#include<algorithm>
#include<cstring>
#define N 100050
using namespace std;
set<int> t[2];
char s[N];
int n,as,v[N],cl,cr;
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++)if(s[i]=='L')t[0].insert(i),cl++;else t[1].insert(i),cr++;
	int ls=1;
	if(cl>cr)while(s[ls]=='R')ls++;
	if(cr>cl)while(s[ls]=='L')ls++;
	v[1]=ls;
	if(s[ls]=='R')t[1].erase(ls);else t[0].erase(ls);
	for(int i=2;i<=n;i++)
	{
		int tp=s[ls]=='L',fg=0;
		set<int>::iterator it=t[tp].lower_bound(ls);
		if(it==t[tp].end())it=t[tp].begin(),as++,fg=1;
		v[i]=*it;t[tp].erase(*it);
		if(t[!tp].size()&&fg)
		{
			if(*t[!tp].begin()<v[i])
			{
				int a=*t[!tp].begin();
				t[!tp].insert(v[i-1]);
				v[i-1]=a;
				t[!tp].erase(a);
			}
		}
		ls=v[i];
	}
	printf("%d\n",as);
	for(int i=1;i<=n;i++)printf("%d ",v[i]);
}