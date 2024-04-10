#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n;
string s;

int32_t main()
{
	IOS;
	cin >> n >> s;
	int z = 0, o = 0;
	for(int i = 0; i < n; i++)
	{
		z += (s[i] == 'z');
		o += (s[i] == 'n');
	}	
	for(int i = 0; i < o; i++)
		cout << 1 << " ";
	for(int i = 0; i < z; i++)
		cout << 0 << " ";
	return 0;
}