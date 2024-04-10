#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e2 + 20;

int t[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	string s;
	cin >> n >> s;

	if(n == 1)
		return cout << "Yes" << endl , 0;

	for(auto ch : s)
		t[ch - 'a']++;

	if(*max_element(t , t + maxn) > 1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;


}