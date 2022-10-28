#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;
 
int32_t main()
{
	IOS;
	int n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	if(n1 <= n2)
		cout << "Second";
	else
		cout << "First"; 
	return 0;
}