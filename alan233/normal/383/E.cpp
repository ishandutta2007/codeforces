#include<bits/stdc++.h>
using namespace std;
#define next Next
#define gc getchar
#define int long long
const int N=(1<<24)+5;
int n,ans,F[N];
char s[15];
/*char buf[1<<21],*p1=buf,*p2=buf;
inline int gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}*/
inline int read()
{
    int ret=0,f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c)){ret=ret*10+c-48;c=gc();}
    if(f)return -ret;return ret;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		int t=0;
		for(int i=1;i<=3;i++)
			t|=(1<<(s[i]-'a'));
		for(int i=t;i>0;i=(i-1)&t)
			if(__builtin_popcount(i)%2==1)F[i]++;
			else F[i]--;
	}
	for(int i=0;i<24;i++)
		for(int j=0;j<(1<<24);j++)
			if(j&(1<<i))F[j]+=F[j^(1<<i)];
	for(int i=0;i<(1<<24);i++)
		ans=ans^(F[i]*F[i]);
	cout<<ans;
}