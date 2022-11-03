#include <bits/stdc++.h>
#define fin freopen("next.in","r",stdin)
#define fout freopen("next.out","w",stdout)
using namespace std;
long long n,a[1000000],ans;
int main() 
{
	cin>>n;
	for (int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	ans=1;
	for ( int i=1;i<=n;i++)
	if (a[i]>=ans) ans++;
	cout<<ans;
}