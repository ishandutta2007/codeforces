#include <bits/stdc++.h>
#define fin freopen("next.in","r",stdin)
#define fout freopen("next.out","w",stdout)
using namespace std;
long long n,m,a[111],b[111],ans;
int main() 
{
	cin>>n>>m;
	ans=(n/5)*(m/5)+(n/5+(n%5>=1))*(m/5+(m%5>=4))+(n/5+(n%5>=2))*(m/5+(m%5>=3))+(n/5+(n%5>=3))*(m/5+(m%5>=2))+(n/5+(n%5>=4))*(m/5+(m%5>=1));
	cout<<ans;
}