#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
#define y1 asd
#define left asdleft
#define right asdright
typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-7;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

int main() {

	sync;
	srand(time(NULL));

#ifdef LOCAL
	input;
//output;
#else

#endif

	int ar[26];
	ms(ar, 0);

	string s;
	cin >> s;

	for(int i = 0; i < (int) s.size(); i++) {
		ar[s[i] - 'a']++;
	}

	int left = (int) s.size() % 2;
	char c = ' ';

	vector<int> v;
	for(int i = 0; i < 26; i++) {
		if(ar[i] % 2) {
			v.push_back(i);
		}
	}

	for(int i = 0; i < (int) v.size() / 2; i++)
	ar[v[i]]++;
	int start = (int) v.size() / 2;
	if(left){
		ar[v[start]]--;
		c = v[start++] + 'a';
	}
	for(int i = start; i < (int) v.size(); i++)
	ar[v[i]]--;

	string ans = "";
	for(int i = 0; i < 26; i++) {
		for(int j = 1; j < ar[i]; j += 2) {
			ans.push_back(i + 'a');
		}
	}

	cout << ans;
	if(c != ' ')
	cout << c;
	reverse(ans.begin(), ans.end());
	cout << ans;

}