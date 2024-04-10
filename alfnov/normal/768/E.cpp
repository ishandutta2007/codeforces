#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,yh=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		int he=0,cnt=0;
		for(int j=1;;j++)
		{
			he+=j,cnt++;
			if(he+(j+1)>a)break;
		}
		yh^=cnt;
	}
	if(yh)printf("NO\n");
	else printf("YES\n");
	return 0;
}