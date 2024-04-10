#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;

pair<int,int> a[maxn];
map<pair<int,int>, int> last;

void solve(){
	int n;
	string s;
	cin >> n >> s;
	last.clear();
	a[0] = {0, 0};
	last[a[0]] = 0;
	int answer = -1, l = -1, r = -1;
	for (int i = 1; i <= n; i++){
		a[i] = a[i - 1];
		if (s[i - 1] == 'L')
			a[i].first --;
		else if (s[i - 1] == 'R')
			a[i].first ++;
		else if (s[i - 1] == 'U')
			a[i].second --;
		else
			a[i].second ++;
		if (last.count(a[i]) and (answer == -1 or answer > i - last[a[i]])){
			answer = i - last[a[i]];
			l = last[a[i]] + 1, r = i;
		}
		last[a[i]] = i;
	}
	if (answer == -1)
		cout << answer << '\n';
	else
		cout << l << " " << r << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		solve();
	}
}