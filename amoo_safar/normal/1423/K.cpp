// I'll Crush you !
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

ll p[N];
ll ps[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ps[1] ++;
	for(ll i = 2; i < N; i++){
		if(!p[i]){
			ps[i] ++;
			if(i * i < N)
				ps[i*i] --;
		}
		for(ll j = i*i; j < N; j += i) p[j] = 1;
	}
	for(int i = 2; i < N; i++) ps[i] += ps[i - 1];
	ll T;
	cin >> T;
	for(int i = 0; i < T; i++){
		ll n;
		cin >> n;
		cout << ps[n] << '\n';
	}
	return 0;
}