#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=105,MOD=998244353;

int n,a[MAXN],b[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int sum=0,all=0,cnt=0;
    b[++cnt]=1;sum=all=a[1];
    for(int i=2;i<=n;i++)
    {
    	if(a[1]>=2*a[i]){sum+=a[i];b[++cnt]=i;}
    	all+=a[i];
    }
    if(sum*2<=all)return 0*printf("0\n");
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++)cout<<b[i]<<" ";
    return 0;
}