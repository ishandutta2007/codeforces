#include <iostream>
#include <algorithm>
using namespace std;

long long num[1501];

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n,m,l,r,ans=0,i,j;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> num[i];
		for(j=1;j<i;j++)
			if(num[j]>num[i]) ans++;
	}
	ans%=2,cin >> m;
	while(m--)
	{
		cin >> l >> r;
		ans=ans^((r-l+1)*(r-l)/2%2);
		if(ans%2) cout << "odd\n";
		else cout << "even\n";
	}
}