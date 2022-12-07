#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int n;
int num[110];
int ans[400010];
char s[400010];
int sim=0;
int qs(char ch)
{
	if('a'<=ch&&ch<='z') return ch-'a'+1;
	if('A'<=ch&&ch<='Z') return ch-'A'+27;
	if('0'<=ch&&ch<='9') return ch-'0'+1+26+26;
}
int make(int l,int r)
{
	int p=1;
	while(l<r)
	{
		while(num[p]==0) p++;
		ans[l]=ans[r]=p;num[p]-=2;
		l++;r--;
	}
}
bool check(int len)
{
	if(len==1) return true;
	if(len%2==0) return false;
	if(n%len!=0) return false;
	int tot=n/len;
	if(tot<sim) return false;
	if((tot-sim)%2!=0) return false;
	return true;
}
int len=0;
void print()
{
	for(int i=1;i<=n;i++)
	{
		int c=ans[i];
		if(c<=26) printf("%c",'a'+c-1);
		else if(c<=52) printf("%c",'A'+c-26-1);
		else printf("%c",'0'+c-26-26-1);
		if(i%len==0) printf(" ");
	}
}
int main()
{
	scanf("%d",&n);scanf("%s",s+1);
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;i++) num[qs(s[i])]++;
	for(int i=1;i<=62;i++)
		if(num[i]%2!=0) sim++;
	if(!sim)
	{
		printf("1\n");len=n;
		make(1,n);print();
		return 0;
	}
	if(sim==1)
	{
		int l=1,p=1;len=n;
		while(num[p]%2==0) p++;
		num[p]--;
		ans[l+len/2]=p;
		printf("1\n");
		make(1,n);print();
		return 0;
	}
	for(int i=max(n-1,1);i>=1;i--)
		if(check(i)) {len=i;break;}
	if(len==1)
	{
		printf("%d\n",n);
		for(int i=1;i<=n;i++) printf("%c ",s[i]);
	}
	else
	{
		int l=1,p=1;
		while(1)
		{
			while(num[p]%2==0&&p<=62) p++;
			if(p>62) break;
			num[p]--;ans[l+len/2]=p;
			l+=len;
		}
		p=1;
		while(l<=n)
		{
			while((num[p]%2!=0||num[p]==0)&&p<=62) p++;num[p]-=2;
			ans[l+len/2]=p;l+=len;
			ans[l+len/2]=p;l+=len;
		}
		l=1;
		while(l<=n) make(l,l+len-1),l+=len;
		printf("%d\n",n/len);print();
	}
}