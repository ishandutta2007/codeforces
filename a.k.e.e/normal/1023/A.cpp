#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int n,m;
string s,t;

int main()
{
    cin>>n>>m>>s>>t;
    int flag=1;
    for(int i=0;i<n;i++)
    	if(s[i]=='*'){flag=0;break;}
    if(flag)return 0*printf(s==t?"YES\n":"NO\n");
    int l=-1,r=t.length();
    for(int i=0;i<n;i++)
    {
    	if(s[i]=='*')break;
    	if(i==m || s[i]!=t[i])return 0*printf("NO\n");
    	l=max(l,i);
    }
    for(int i=1;i<=n;i++)
    {
		if(s[n-i]=='*')break;
    	if(m-i<0 || s[n-i]!=t[m-i])return 0*printf("NO\n");
		r=min(r,m-i);
    }
    if(l>=r)printf("NO\n");
    else printf("YES\n");
    return 0;
}