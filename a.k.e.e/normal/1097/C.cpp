#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005,MOD=998244353;

int n;
string s;
int d[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n;
    for(int i=1;i<=n;i++)
	{
		cin>>s;
		int cnt=0;
		for(int j=0;j<s.length();j++)
		{
			if(s[j]=='(')++cnt;
			else --cnt;
			if(cnt<0){d[i]=-1;break;}
		}
		d[i]=cnt;
		if(d[i]<0)
		{
			cnt=0;
			for(int j=s.length()-1;j>=0;j--)
			{
				if(s[j]=='(')++cnt;
				else --cnt;
				if(cnt>0){d[i]=1;break;}
			}
			d[i]=cnt;
			if(d[i]>0)d[i]=1<<30;
		}
	}
	sort(d+1,d+n+1);
	int r=n;
	for(;d[r]==(1<<30);--r);
	int l=1,ans=0;
	while(l<r)
		if(d[l]+d[r]<0)++l;
		else if(d[l]+d[r]>0)--r;
		else ++l,--r,++ans;
	printf("%d\n",ans);
    return 0;
}