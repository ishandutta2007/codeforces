#include <iostream>
#include <cstring>
using namespace std;

struct ban
{
	long long x,vac;
};
ban a[27];
const long long N=1000000007; 
long long n,m,k,ans,copyanst,anst,sn,minum,minu,t,mini,z,cpyans,cpyanst;
char s[1000005];
int funkc(char y)
{
	return y - 'a';
}
int main()
{
	int i,j;
	cin>>n>>m>>s;
	sn=strlen(s);
	for(i=sn;i>=1;i--)
	{
		s[i]=s[i-1];
	}
	ans=1;
	for(i=1;i<=sn;i++)
	{
		t=funkc(s[i]);
		cpyans=ans;
//////////////////////////////////////////////////////////////////
		ans=(ans+N+ans-a[t].vac)%N;
		a[t].vac=cpyans%N;
		a[t].x=i;
	}
	for(i=sn+1;i<=n+sn;i++)
	{
		minu=9999999999999;
		for(j=0;j<m;j++)
		{
			if(a[j].x<minu)
			{
				minu=a[j].x;
				mini=j;
			}
		}
//////////////////////////////////////////////////////////////////
		cpyans=ans;
//////////////////////////////////////////////////////////////////
		ans=(ans+N+ans-a[mini].vac)%N;
		a[mini].vac=cpyans;
		a[mini].x=i;
	}
	cout<<ans%N<<endl;
	return 0;
}