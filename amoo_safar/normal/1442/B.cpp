// nemibinam invara kasi mesle khodemono !
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

const ll Mod = 998244353;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[N], b[N], p[N], mk[N];
void Main(){
	ll n, k;
	cin >> n >> k;
	set<int> st;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		p[a[i]] = i;
		st.insert(i);
	}
	for(int i = 0; i < k; i++){
		cin >> b[i];
		b[i] = p[b[i]];
		mk[b[i]] = 1;
	}

	ll ans = 1;
	for(int i = 0; i < k; i++){
		mk[b[i]] = 0;
		auto it = st.find(b[i]);
		vector<int> V;
		if(it != st.begin()){
			if(!mk[*prev(it)])
				V.pb(*prev(it));
		}
		if(next(it) != st.end()){
			if(!mk[*next(it)])
				V.pb(*next(it));
		}

		ans = ans * V.size();
		ans %= Mod;
		if(!V.empty()){
			st.erase(V[0]);
		}
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();

	return 0;
}