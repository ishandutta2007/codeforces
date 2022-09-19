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

int a[N];

int Main(){
	int n, k;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i] = abs(a[i]);
	}
	int up = 1;
	for(int i = 0; i < n; i++) up *= 3;
	for(int mk = 1; mk < up; mk ++){
		int sm = 0;
		int y = mk;
		for(int j = 0; j < n; j++){
			if(y % 3 == 1)
				sm += a[j];
			if(y % 3 == 2)
				sm -= a[j];
			y/=3;
		}
		if(sm == 0)
			return cout << "YES\n", 0;
	}
	cout << "NO\n";
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}