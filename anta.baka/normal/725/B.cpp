#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
// head

char e[6] = {'f', 'e', 'd', 'a', 'b', 'c'};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	ll w = 0;
	while(!isalpha(s[0])) {
		w = w * 10 + (s[0] - '0');
		s.erase(0,1);
	}
	ll ans = ((w-1) / 4) * 16ll;
	w %= 4; w = (w + 3) % 4;
	if(w % 2 == 1)
		ans += 7;
	for(int i = 0; i < 6; i++)
		if(s[0] == e[i])
			ans += i+1;
	cout << ans;
}