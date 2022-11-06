#include<bits/stdc++.h>
using namespace std;
#define ll long long
int m,c[30];char s[100005];
int main()
{
	scanf("%d%s",&m,s+1);
	for(int i=1;i<=m;i++)c[s[i]-'a']++;
	int z=25,e=4,r=17,o=14,n=13,res=-1,id=-1;
	for(int i=0;i<=m;i++)
	{
		if(c[o]>=i&&c[n]>=i&&c[e]>=i)
		{
			int ans=min(min(c[z],c[e]-i),min(c[r],c[o]-i));
			if(i+ans>res)res=i+ans,id=i;
			else if(i+ans==res)id=i;
		}
	}
	for(int i=1;i<=id;i++)printf("%d ",1);
	for(int i=1;i<=res-id;i++)printf("%d ",0);
	return 0;
}