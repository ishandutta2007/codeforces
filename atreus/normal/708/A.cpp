#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++){
		if (s[i] == 'a')
			continue;
		for (int j = i; j < n; j++){
			if (s[j] == 'a')
				return cout << s << endl, 0;
			int p = (int)(s[j] - 'a');
			p --;
			s[j] = (char)(p + 'a');
		}
		cout << s << endl;
		return 0;
	}
	s.back() = 'z';
	cout << s << endl;
}