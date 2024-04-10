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
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
const ld E = 1e-7;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 100;
#else
const ll MAX = 2e5 + 1;
#endif

vector<int> vec;

void solve(){
	vector<ii> v;
	for(int i = 0; i < (int) vec.size(); i++)
		v.push_back(make_pair(vec[i], i));
	sort(v.rbegin(), v.rend());
	int a = -1, b = -1, c = -1, ans = 0;
	for(int i = 0; i < min((int) v.size(), 3) && v[i].first > 0; i++){
		if(i == 0)
			a = v[i].second;
		else if(i == 1)
			b = v[i].second;
		else
			c = v[i].second;
		ans++;
	}
	for(int i = 0; i < (int) v.size(); i++){
		if(i == a){
			cout << "pushStack" << endl;
		}else if(i == b){
			cout << "pushQueue" << endl;
		}else if(i == c){
			cout << "pushFront" << endl;
		}else{
			cout << "pushBack" << endl;
		}
	}
	cout << ans;
	if(a != -1)
		cout << " popStack";
	if(b != -1)
		cout << " popQueue";
	if(c != -1)
		cout << " popFront";
	cout << endl;
	vec.clear();
}

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x == 0){
			solve();
		}else{
			vec.push_back(x);
		}
	}
	for(int i = 0; i < (int) vec.size(); i++)
		cout << "pushFront" << endl;

}