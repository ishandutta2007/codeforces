#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define ll long long
#define vi vector<int>
int n,ans;char s[1000005];
int main()
{
	scanf("%d%s",&n,s+1);
	int s1=0,s2=0,lst=-1;
	for(int i=1;i<=n;i++)
	{
		s1+=s[i]=='(';
		s2+=s[i]==')';
		if(s1==s2&&lst>0)ans+=i-lst+1,lst=-1;
		if(s1<s2&&lst<0)lst=i;
	}
	if(s1!=s2){puts("-1");return 0;}
	printf("%d\n",ans);
	return 0;
}