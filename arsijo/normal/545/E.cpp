#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define print2(ar, n, m) for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
#define print(ar, n) for(int i = 0; i < n; i++) cout << ar[i] <<  " ";
#define sqr(a) ((a) * (a))
#define endl "\n"
#define x first
#define y second
#define mod % 1000000007
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef map<int, int>::iterator mit;
const ll MAX = 1000000000000000;
const ld E = 1e-11;

struct t{
	ll val, to, id;
	t(ll a, ll b, ll c){
		val = a;
		to = b;
		id = c;
	}
};

struct p{
	ll a, b, c;
	p(ll d, ll e, ll f){
		a = d;
		b = e;
		c = f;
	}
};

bool operator<(p a, p b){
	return (a.a != b.a ? a.a < b.a : (a.c != b.c ? a.c < b.c : a.b < b.b));
}

int main() {

	sync;
	//input;

	ll n, m;
	cin >> n >> m;

	vector<t> v[n + 1];

	for(int i = 1; i <= m; i++){
		ll a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(t(c, b, i));
		v[b].push_back(t(c, a, i));
	}

	ll pos;
	cin >> pos;

	bool used[n + 1];
	ms(used);

	ll ansId[n + 1], minLen[n + 1], lastAdd[n + 1];
	ms(ansId);
	ms(lastAdd);
	for(int i = 0; i <= n; i++)
		minLen[i] = MAX;
	minLen[pos] = 0;

	set<p> s;
	s.insert(p(0, pos, 0));

	vector<int> f;

	ll sum = 0;

	while(!s.empty()){
		ll pos = s.begin()->b;
		s.erase(s.begin());
		if(ansId[pos] != 0)
			f.push_back(ansId[pos]);
		sum += lastAdd[pos];
		//cout << "+ " << lastAdd[pos] << " " << minLen[pos] << endl;
		used[pos] = true;
		for(int i = 0; i < (int) v[pos].size(); i++){
			int to = v[pos][i].to, val = v[pos][i].val, id = v[pos][i].id;
			if((minLen[pos] + val < minLen[to] || (minLen[pos] + val == minLen[to] && val < lastAdd[to])) && !used[to]){
				ansId[to] = id;
				if(minLen[to] != MAX)
					s.erase(p(minLen[to], to, lastAdd[to]));
				minLen[to] = minLen[pos] + val;
				lastAdd[to] = val;
				s.insert(p(minLen[to], to, lastAdd[to]));
				//cout << "update " << to << " now " << minLen[to] << " " << lastAdd[to] << " " << ansId[to] << endl;
			}
		}
	}

	cout << sum << endl;
	for(int i = 0; i < (int) f.size(); i++)
		cout << f[i] << " ";

}