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
int ans[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int cur=0;
    scanf("%s",s+1);n=strlen(s+1);
    for(int i=2;i*2<=n;i+=2)
    	if(s[i]==s[n-i+1] || s[i]==s[n-i+2])ans[++cur]=i;
    	else ans[++cur]=i-1;
    for(int i=1;i<=cur;i++)putchar(s[ans[i]]);
    if((n+1)/2>ans[cur])putchar(s[(n+1)>>1]);
    for(int i=cur;i;i--)putchar(s[ans[i]]);
    return 0;
}