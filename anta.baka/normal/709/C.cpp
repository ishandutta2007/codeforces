#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back
#define min(a, b) (a < b ? a : b)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	int n = (int)s.length(), p1 = 0;
	while(p1 < n && s[p1] == 'a')
		p1++;
	if(p1 == n) {
		s[n-1] = 'z';
		cout << s;
		return 0;
	}
	int p2 = p1;
	while(p2 < n && s[p2] != 'a')
		p2++;
	for(int i = p1; i < p2; i++)
		s[i]--;
	cout << s;
}