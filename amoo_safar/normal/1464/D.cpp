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
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


ll mul(ll a, ll b){
	return (a * b) % Mod;
}

ll power(ll x, ll b){
	ll res = 1;
	for(int i = 0; i < b; i++)
		res = mul(res, x);
	return res;
}

int mk[N], p[N];

int cnt = 0;
void DFS(int u){
	cnt ++;
	mk[u] = 1;
	if(!mk[p[u]])
		DFS(p[u]);
}

int Main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		mk[i] = 0;
	}
	vector<int> V[3];
	for(int i = 1; i <= n; i++){
		if(mk[i]) continue;
		cnt = 0;
		DFS(i);
		// cerr << "# " << cnt << '\n';
		V[cnt % 3].pb(cnt);
	}

	if(n % 3 == 0){
		cout << power(3, n / 3) << ' ';
		
		int rq = n/3;

		int nw = V[0].size() + V[1].size() + V[2].size();

		int c1 = V[1].size();
		int c2 = V[2].size();
		int mv;
		if(c1 == c2)
			mv = c1;
		else {
			if(c1 > c2) swap(c1, c2);
			mv = c1 + 2 * ((c2 - c1)/3);
		}
		cout << mv + rq - (nw - mv) << '\n';
		// cerr << "! " << mv << ' ' << rq << '\n';
		return 0;
	}
	if(n % 3 == 2){
		cout << mul(2, power(3, n / 3)) << ' ';
		int rq = (n + 1) / 3;

		int nw = V[0].size() + V[1].size() + V[2].size();

		int c1 = V[1].size();
		int c2 = V[2].size();
		int mv;
		if(c1 > c2){
			mv = c2 + ((c1 - c2) - ((c1 - c2 + 1) / 3));
		} else {
			mv = c1 + ((c2 - c1) - ((c2 - c1 + 2) / 3));
		}
		cout << mv + rq - (nw - mv) << '\n';
		return 0;
	}

	sort(all(V[1]));

	cout << mul(4, power(3, (n - 4) / 3)) << ' ';
	int rq = (n + 2) / 3;

	int nw = V[0].size() + V[1].size() + V[2].size();

	int c1 = V[1].size();
	int c2 = V[2].size();
	int mv = 0;

	if(c1 == 1 && c2 == 0){
		if(V[1][0] == 1) mv = 1, rq --;
		else mv = 0, rq --;
	} else {
		if(c1 > c2){
			int fl = 0;
			if(V[1].back() > 1) fl = 1;
			if(fl == 1){
				rq --;
				c1 --;

				if(c1 == c2)
					mv = c1;
				else {
					if(c1 > c2) swap(c1, c2);
					mv = c1 + 2 * ((c2 - c1)/3);
				}
			} else {
				for(int y = 0; y < 2; y++){
					if(c2) c2 --;
					else c1 -= 2, mv ++;
				}
				// cerr << "!! " << c1 << ' ' << c2 << '\n';
				if(c1 == c2)
					mv += c1;
				else {
					if(c1 > c2) swap(c1, c2);
					mv += c1 + 2 * ((c2 - c1)/3);
				}
			}
		} else {
			mv = c1 + ((c2 - c1 - 2) - ((c2 - c1 - 2) / 3));
		}
	}
	cout << mv + rq - (nw - mv) << '\n';
	// cout << "-1 -1\n";
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T --) Main();
	return 0;
}