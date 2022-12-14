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
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += (s[i] == 'a');
	cout << min(2 * cnt - 1, n) << endl;
}