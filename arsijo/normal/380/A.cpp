#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
const ld E = 1e-7;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 100;
#else
const ll MAX = 1e5 + 1;
#endif

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	vector<pair<ll, ii> > vec;
	vec.reserve(n);

	ll s = 0;

	for(int i = 0; i < n; i++){
		ll a;
		cin >> a;
		if(a == 1){
			ll q;
			cin >> q;
			s++;
			vec.push_back(make_pair(1LL, make_pair(q, 0LL)));
		}else{
			ll b, c;
			cin >> b >> c;
			s += b * c;
			vec.push_back(make_pair(2LL, make_pair(b, c)));
		}
	}

	int size = (int) min(s, (ll) 1e5);
	int ar[size];
	for(int i = 0, j = 0; i < n && j < size; i++){
		if(vec[i].first == 1){
			ar[j++] = vec[i].second.first;
		}else{
			for(int a = 0; a < vec[i].second.second && j < size; a++){
				for(int b = 0; b < vec[i].second.first && j < size; b++){
					ar[j++] = ar[b];
				}
			}
		}
	}

	int m;
	cin >> m;

	ll t[m];
	for(int i = 0; i < m; i++)
		cin >> t[i];

	ll sum = 0;
	for(int i = 0, j = 0; i < n && j < m; i++){
		if(vec[i].first == 1){
			sum++;
			if(t[j] == sum){
				cout << ar[t[j++] - 1] << " ";
			}
		}else{
			ll new_sum = sum + vec[i].second.first * vec[i].second.second;
			while(j < m && t[j] <= new_sum){
				cout << ar[(t[j++] - sum - 1) % vec[i].second.first] << " ";
			}
			sum = new_sum;
		}
	}
}