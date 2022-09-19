// vaziat meshki-ghermeze !
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
int mk[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	int M = 3;
	while(T --){
		M ++;
		int a, b;
		cin >> a >> b;
		int f = (a + b) / 2;
		int s = a + b - f;
		int mn = abs(f - a);
		int mx = 0;
		if(f >= a){
			mx = min(a, s);
		} else {
			mx = min(f, b);
		}
		for(int i = mn; i <= mn + 2 * mx; i += 2) mk[i] = M;
		s = (a + b) / 2;
		f = a + b - s;
		mn = abs(f - a);
		mx = -1;
		if(f >= a){
			mx = min(a, s);
		} else {
			mx = min(f, b);
		}
		for(int i = mn; i <= mn + 2 * mx; i += 2) mk[i] = M;
		int cnt = 0;
		for(int i = 0; i <= a + b; i++) if(mk[i] == M) cnt ++;
		cout << cnt << '\n';
		for(int i = 0; i <= a + b; i++) if(mk[i] == M) cout << i << ' ';
		cout << '\n';
	}
	return 0;
}