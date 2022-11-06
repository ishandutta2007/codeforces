#include<bits/stdc++.h>
using namespace std;
int n,ff;char s[1005];
vector<int>V1,V2;
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(s[i]=='('&&s[j]==')')ff=1;
	if(!ff){puts("0");return 0;}
	puts("1");
	for(int l=1,r=n;l<r;)
	{
		while(s[l]==')'&&l<r)l++;
		while(s[r]=='('&&l<r)r--;
		if(l==r)break;
		V1.push_back(l);V2.push_back(r);
		l++;r--;
	}
	reverse(V2.begin(),V2.end());
	printf("%d\n",(int)V1.size()+(int)V2.size());
	for(int i:V1)printf("%d ",i);
	for(int i:V2)printf("%d ",i);
	return 0;
}