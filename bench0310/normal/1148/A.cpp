#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a,b,ab;
	cin >> a >> b >> ab;
	cout << 2ll*ab+2ll*min(a,b)+((a!=b)?1ll:0ll) << endl;
	return 0;
}