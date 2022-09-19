// Doooop !
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

int a[N][5];
bool Win(int i, int j){
	int cnt = 0;
	for(int k = 0; k < 5; k++) cnt += (a[i][k] <= a[j][k]);
	return cnt >= 3;
}

int Main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 5; j++)
			cin >> a[i][j];
	int mx = 1;
	for(int i = 2; i <= n; i++)
		mx = (Win(mx, i) ? mx : i);
	for(int i = 1; i <= n; i++)
		if(!Win(mx, i))
			return cout << "-1\n", 0;
	cout << mx << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}