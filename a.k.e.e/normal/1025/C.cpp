#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int MAXN=100005;

int n;
char s[MAXN];
int len[MAXN],enl[MAXN];

int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    int ans=0,now=1;
    for(int i=2;i<=n;i++)
    	if(s[i]!=s[i-1])now++;
    	else ans=max(ans,now),now=1;
    ans=max(ans,now);
    if(s[1]!=s[n])
    {
    	int len=2;
	    for(int i=2;i<=n;i++)
	    	if(s[i]!=s[i-1])++len;
	    	else break;
	    for(int i=n-1;i>0;i--)
	    	if(s[i]!=s[i+1])++len;
	    	else break;
	    ans=max(ans,len);
	}
	if(ans>n)ans=n;
	cout<<ans<<endl;
    return 0;
}