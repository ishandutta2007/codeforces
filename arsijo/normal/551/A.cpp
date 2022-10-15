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
//#define x first
//#define y second
#define mod % 1000000007
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef map<int, int>::iterator mit;
const ll MAX = 1000;
typedef ll array[MAX][MAX];
const ld E = 1e-11;

int main() {

	int n;
	cin >> n;

	vector<ii> vec;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		vec.push_back(make_pair(a, i));
	}

	int ar[n];
	ms(ar);
	sort(vec.rbegin(), vec.rend());
	ar[vec[0].second] = 1;
	for(int i = 1; i < n; i++){
		ar[vec[i].second] = (vec[i].first == vec[i - 1].first ? ar[vec[i - 1].second] : i + 1);
	}

	for(int i = 0; i < n; i++)
		cout << ar[i] << " ";

}