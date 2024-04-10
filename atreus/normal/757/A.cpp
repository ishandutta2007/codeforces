#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

map<char,int> mp;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++)
		mp[s[i]] ++;
	
	cout << min({mp['B'], mp['u']/2, mp['l'], mp['b'], mp['a']/2, mp['s'], mp['r']}) << '\n';
}