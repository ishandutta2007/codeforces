#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
int n,i,j,a[2005],ans=1<<30;
set<int> st;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
	for(i=1;i<=n;++i)
		if(st.count(a[i]))
			break;
		else
			st.insert(a[i]);
	if(i>n)
	{
		printf("0");
		return 0;
	}
	for(i=1;i<=n;++i)
	{
		st.clear();
		for(j=1;j<i;++j)
			if(st.count(a[j]))
				break;
			else
				st.insert(a[j]);
		if(j<i)
			continue;
		for(j=n;;--j)
			if(st.count(a[j]))
			{
				ans=min(ans,j-i+1);
				break;
			}
			else
				st.insert(a[j]);
	}
	printf("%d",ans);
	return 0;
}