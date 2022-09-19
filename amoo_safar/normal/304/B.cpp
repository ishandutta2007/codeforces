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

ll ln[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll ln2[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int n){
	if(n % 400 == 0) return 1;
	if(n % 100 == 0) return 0;
	if(n % 4 == 0) return 1;
	return 0;
}

ll con(str x){
	ll res = 0;
	for(auto c : x) res = (10 * res) + (c - '0');
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll y1, m1, d1;
	ll y2, m2, d2;
	str s;
	cin >> s;
	y1 = con(s.substr(0, 4));
	m1 = con(s.substr(5, 2));
	d1 = con(s.substr(8, 2));

	cin >> s;
	y2 = con(s.substr(0, 4));
	m2 = con(s.substr(5, 2));
	d2 = con(s.substr(8, 2));
	if(tuple<ll, ll, ll>(y1,m1,d1) > tuple<ll, ll, ll>(y2,m2,d2)){
		swap(y1,y2);
		swap(m1,m2);
		swap(d1,d2);
			
	}

	if(leap(y1)) ln[2] ++;
	ll ans = 0;
	while(y1 != y2 || m1 != m2 || d1 != d2){
		d1 ++;
		ans ++;
		if(d1 > ln[m1]){
			d1 = 1;
			m1 ++;
		}
		if(m1 == 13){
			if(leap(y1)) ln[2] --;
			m1 = 1;
			y1 ++;
			if(leap(y1)) ln[2] ++;
		}

	}

	cout << ans << '\n';
	return 0;
}