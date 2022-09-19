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

const int Mod = 1000000007LL;
const int N = 3e5 + 10;
const int Log = 30;
const ll Inf = 2242545357980376863LL;

int A[N];

int Main(){
	str S;
	cin >> S;
	str ans = "";
	int n = S.size();
	vector<int> cnt(30, n + 1);
	for(int i = 0; i < n; i++){
		int c = S[i] - 'a';
		cnt[c] = i;
	}
	int st = *min_element(all(cnt));
	cout << S.substr(st) << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}