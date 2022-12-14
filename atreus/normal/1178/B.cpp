#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 5;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	ll w = 0, wo = 0;
	ll answer = 0;
	for (int i = 1; i < n; i++){
		if (i < n - 1 and s[i] == 'v' and s[i + 1] == 'v')
			answer += wo;
		if (s[i] == 'o')
			wo += w;
		if (s[i] == 'v' and s[i - 1] == 'v')
			w ++;
	}
	cout << answer << endl;
}