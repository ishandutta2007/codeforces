#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;
typedef long long LL;
const int V=1000100;
char s[V],t[V];
int gcd(int x,int y)
{
    if(!y)return x;
    if(!x)return y;
    return gcd(y,x%y);
}
LL n,m;
int ct[V][26];
int main()
{
    while(cin>>n>>m)
    {
        scanf("%s%s",s,t);
        int ls=strlen(s);
        int lt=strlen(t);
        int gd=gcd(ls,lt);
        LL cp=n*ls/((LL)ls/gd*lt);
        memset(ct,0,sizeof(ct));
        for(int i=0;i<lt;i++)
        ct[i%gd][t[i]-'a']++;
        LL ret=(LL)ls/gd*lt;
        for(int i=0;i<ls;i++)
        ret-=ct[i%gd][s[i]-'a'];
        cout<<ret*cp<<endl;
    }
    return 0;
}