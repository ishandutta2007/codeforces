#include <iostream>
using namespace std;


int main()
{
	long long n,a,b,i;
	cin >> n >> a >> b;
	for(i=0;a*i<=n;i++)
		if((n-a*i)%b==0) break;
	if(a*i>n) cout << "NO\n";
	else cout << "YES\n" << i << " " << (n-a*i)/b << "\n";
 }