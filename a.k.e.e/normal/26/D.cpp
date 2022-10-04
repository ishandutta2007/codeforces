#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005,MOD=998244353;

int n,m,k;

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n>>m>>k;
    if(n-m<=-k-1)return 0*printf("0\n");
    if(k+1>m)return 0*printf("1\n");
    double ans=1;
    for(int i=0;i<=k;i++)
    	ans=ans*(m-i)/(n+i+1);
    printf("%.8lf\n",1-ans);
    return 0;
}