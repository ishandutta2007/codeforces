#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=300005;

int n;
ll x,y;
char s[MAXN];

int main()
{
	#ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n>>x>>y>>(s+1);
    int cnt=0;
    s[0]='1';
    for(int i=1;i<=n;i++)
    	if(s[i]=='0' && s[i-1]=='1')cnt++;
    if(cnt)cout<<min(y*cnt,x*(cnt-1)+y)<<endl;
    else cout<<0<<endl;
    return 0;
}