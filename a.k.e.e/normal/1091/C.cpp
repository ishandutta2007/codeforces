#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005,MOD=998244353;

ll ans[MAXN];

int main()
{
    ll n;int m=0;
    cin>>n;
    for(int i=1;i*i<=n;i++)
    	if(n%i==0)
		{
			ans[++m]=i+n*(i-1)/2;
			if(i*i!=n)ans[++m]=n/i+n*(n/i-1)/2;
		}
	sort(ans+1,ans+m+1);
	for(int i=1;i<m;i++)cout<<ans[i]<<" ";
	cout<<ans[m]<<endl;
	return 0;
}