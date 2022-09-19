// Son
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll Mod = 1000000007LL;
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int Main(){
	int n;
	string S;
	cin >> S;
	bool fl = (S.back() == 'B');
	int sm = 0;
	for(auto c : S){
		sm += (c == 'A' ? 1 : -1);
		fl &= (sm >= 0);
	}
	cout << (fl ? "YES" : "NO") << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t --) Main();
	return 0;
}