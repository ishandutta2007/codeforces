#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=1000005;

int n;
char s[MAXN];
ll pre[MAXN],suf[MAXN],ans;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%s",s+1);
	n=strlen(s+1);
    for(int i=2;i<=n;i++)
    	if(s[i]=='v' && s[i-1]=='v')pre[i]=pre[i-1]+1;
    	else pre[i]=pre[i-1];
    for(int i=n-1;i;i--)
    	if(s[i]=='v' && s[i+1]=='v')suf[i]=suf[i+1]+1;
    	else suf[i]=suf[i+1];
    for(int i=2;i<n;i++)
    	if(s[i]=='o')ans+=pre[i-1]*suf[i+1];
    cout<<ans<<endl;
    return 0;
}