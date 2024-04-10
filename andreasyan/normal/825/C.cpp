#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1005;

long long n,m;
long long a[N];
long long ans;
int main()
{
	int i;
	cin>>n>>m;
	for(i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	for(i=0;i<n;++i)
	{
		if(m*2>=a[i])
		{
			m=max(m,a[i]);
			continue;
		}
		while(m*2<a[i])
		{
			++ans;
			m*=2;
		}
		m=max(m,a[i]);
	}
	cout<<ans<<endl;
	return 0;
}