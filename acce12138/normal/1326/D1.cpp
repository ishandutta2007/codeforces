#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ff first
#define ss second
const int maxn = 2000111;

char s[maxn],t[maxn];
int len[maxn],n;
void solve()
{
	scanf("%s",s+1);n=strlen(s+1);
	int nn=0;
	for(int i=1;i<=n;i++)
	{
		t[++nn]='*';
		t[++nn]=s[i];
	}
	t[++nn]='*';
	t[nn+1]='$';
	
	int mx=0,pos=0;
	for(int i=1;i<=nn;i++)
	{
		if(mx>i)len[i]=min(mx-i,len[2*pos-i]);
		else len[i]=1;
		while(t[i-len[i]]==t[i+len[i]]) len[i]++;
        if(len[i] + i > mx)
        {
            mx = len[i] + i;
            pos = i;
        }
	}
	
	int val=0;while(val<n&&s[val+1]==s[n-val])val++;
	if(val==n)
	{
		printf("%s\n",s+1);
		return;
	}
	pair<int,pair<int,int>>ans=mp(0,mp(0,0));
	for(int i=1;i<=n;i++)
	{
		int tmp=len[i*2]/2,l=i-tmp+1,r=i+tmp-1,ll=l-1,rr=n-r;
		if(ll<=rr&&ll<=val)ans=max(ans,mp(i*2-1,mp(i,1)));
		if(rr<=ll&&rr<=val)ans=max(ans,mp((n-i+1)*2-1,mp(i,2)));
	}
	for(int i=1;i<n;i++)
	{
		int tmp=len[i*2+1]/2,l=i-tmp+1,r=i+tmp,ll=l-1,rr=n-r;
		if(ll<=rr&&ll<=val)ans=max(ans,mp(i*2,mp(i,3)));
		if(rr<=ll&&rr<=val)ans=max(ans,mp((n-i)*2,mp(i,4)));
	}
	pos=ans.ss.ff;int tp=ans.ss.ss;
	if(tp==1)
	{
		for(int i=1;i<=pos;i++)putchar(s[i]);
		for(int i=pos-1;i>=1;i--)putchar(s[i]);
	}
	if(tp==2)
	{
		for(int i=n;i>=pos;i--)putchar(s[i]);
		for(int i=pos+1;i<=n;i++)putchar(s[i]);
	}
	if(tp==3)
	{
		for(int i=1;i<=pos;i++)putchar(s[i]);
		for(int i=pos;i>=1;i--)putchar(s[i]);
	}
	if(tp==4)
	{
		for(int i=n;i>pos;i--)putchar(s[i]);
		for(int i=pos+1;i<=n;i++)putchar(s[i]);
	}
	puts("");
}
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
	return 0;
}