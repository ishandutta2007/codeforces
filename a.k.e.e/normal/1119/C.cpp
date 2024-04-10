#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=505;

int n,m,a[MAXN][MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int x;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=m;j++)
    		cin>>a[i][j];
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=m;j++)
    		{cin>>x;a[i][j]^=x;}
    for(int i=1;i<=n;i++)
    {
    	int s=0;
    	for(int j=1;j<=m;j++)s^=a[i][j];
    	if(s)return 0*printf("No\n");
    	for(int j=1;j<=m;j++)
    		a[i+1][j]^=a[i][j];
    }
    for(int j=1;j<=m;j++)
    	if(a[n+1][j])return 0*printf("No\n");
    printf("Yes\n");
    return 0;
}