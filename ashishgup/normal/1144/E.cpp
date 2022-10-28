#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int store[N];
string s, t;
vector<int> v, v2;

int32_t main()
{
	IOS;
	cin >> n >> s >> t;
	int cur = 0;
	string ans = "";
	int car = 0;
	for(int i = n - 1; i >= 0; i--)
	{	
		int cur = 0;
		cur += (s[i] - 'a');
		cur += (t[i] - 'a');
		cur += car;
		store[i] = cur;
		int ch = cur % 26;
		v.push_back(ch);
		car = cur / 26;
	}
	if(car)
		v.push_back(car);
	reverse(v.begin(), v.end());
	int carry = 0;
	for(int i=0;i<v.size();i++)
	{
		if(i==0 && v[i]==1 && carry==0)
		{
			carry = 1;
			continue;
		}
		else if(carry == 0)
		{
			cout << (char) (v[i]/2 + 'a');
			carry = v[i] % 2;
		}
		else
		{
			v[i] += 26;
			cout << (char) (v[i]/2 + 'a');
			carry = v[i] % 2;
		}
	}
	cout << ans;
	return 0;
}