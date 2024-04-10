#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=25,MOD=998244353;

int n,a[MAXN];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    	cin>>a[i];
    for(int i=0;i<(1<<n);i++)
    {
    	int ans=0;
    	for(int j=0;j<n;j++)
    		if(i&(1<<j))ans+=a[j];
    		else ans-=a[j];
    	if(ans%360==0)return 0*printf("YES\n");
    }
    printf("NO\n");
    return 0;
}