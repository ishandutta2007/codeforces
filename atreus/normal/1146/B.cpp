/***
  * Virtual Contest: Forethought Future Cup - Elimination Round
***/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	string t;
	for (int i = 0; i < n; i++)
		if (s[i] != 'a')
			t += s[i];
	int m = t.size();
	if (t == "")
		return cout << s << endl, 0;
	if (m % 2 == 1 or t.substr(0, m / 2) != t.substr(m / 2, m / 2))
		return cout << ":(" << endl, 0;
	int cnt = 0;
	string fi, se;
	for (int i = 0; i < n; i++){
		cnt += (s[i] != 'a');
		if (cnt > m / 2){
			se += s[i];
			if (s[i] == 'a')
				return cout << ":(" << endl, 0;
		}
		else
			fi += s[i];
	}
	cout << fi << endl;
}