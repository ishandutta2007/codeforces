#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN=300005;

int n;
string s[MAXN];
int sl[MAXN],sr[MAXN];

int main()
{
    #ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    int cnt,mc=0;
    bool flag;
    for(int i=1;i<=n;i++)
    {
    	cin>>s[i];
    	cnt=0;
    	flag=true;
    	for(int j=0;j<s[i].length();j++)
    	{
    		if(s[i][j]=='(')cnt++;
    		else cnt--;
    		if(cnt<0)
			{
				flag=false;
				break;
			}
    	}
    	if(flag)sl[cnt]++;
    	//cout<<cnt<<" ";
    	
    	cnt=0;
    	flag=true;
    	for(int j=s[i].length()-1;j>=0;j--)
    	{
    		if(s[i][j]==')')cnt++;
    		else cnt--;
    		if(cnt<0)
			{
				flag=false;
				break;
			}
    	}
    	if(flag)sr[cnt]++;
    	//cout<<cnt<<endl;
    	mc=max(mc,cnt);
    }
    long long ans=0;
    for(int i=0;i<=mc;i++)
    	ans+=((long long)sl[i])*sr[i];
    cout<<ans<<endl;
    return 0;
}