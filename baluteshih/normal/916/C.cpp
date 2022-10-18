#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

const long long prime=300007;

int main()
{
	long long n,m,i,j;
	cin >> n >> m;
	if(n==2 && m==1)
	{
		cout << "3 3\n1 2 3\n";
		return 0;
	}
	cout << "3 300007\n";
	for(i=n;i>2;i--,m--)
		cout << 1 << " " << i << " " << 3 << "\n";
	cout << 1 << " " << 2 << " " << prime-3*(n-2) << "\n",m--;
	if(!m) return 0;
	for(i=2;i<=n;i++)
		for(j=i+1;j<=n;j++)
		{
			cout << i << " " << j << " 1000000000\n";
			m--;
			if(!m) return 0;
		}
}