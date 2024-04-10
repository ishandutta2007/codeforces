// har ki ro didi goft mikhad beshe meslemon !
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

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int x[N], y[N];

str s[N];

int Main(){
	int n;
	cin >> n;
	vector<int> cnt(3, 0);
	for(int i = 0; i < n; i++){
		cin >> s[i];
		for(int j = 0; j < n; j++){
			if(s[i][j] == 'X')
				cnt[(i + j) % 3] ++;
		}
	}
	int idx = (min_element(all(cnt)) - cnt.begin());
	for(int i = 0; i < n; i++){
		//cin >> s[i];
		for(int j = 0; j < n; j++){
			if((s[i][j] == 'X') && ((i + j) % 3 == idx))
				s[i][j] = 'O';
		}
		cout << s[i] << '\n';
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}