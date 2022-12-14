#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000 + 10;
const int mod = 1e9 + 7;

int a[maxn], b[maxn];

int get(string s){
	int n = s.size();
	for (int i = 0; i < n; i++)
		a[i+1] = a[i] + (s[i] == '0');
	for (int i = 0; i < n; i++)
		b[i+1] = b[i] + (s[n-i-1] == '1');
	int mnm = n;
	for (int i = 1; i <= n; i++)
		mnm = min(mnm, a[i] + b[n-i]);
	return mnm;
}

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		string s;
		cin >> s;
		int ret = get(s);
		for (int i = 0; i < (int)s.size(); i++)
			if (s[i] == '0')
				s[i] = '1';
			else
				s[i] = '0';
		ret = min(ret, get(s));
		cout << ret << '\n';
	}
}