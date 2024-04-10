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
#define x first
#define y second
#define mod % 1000000007
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef map<int, int>::iterator mit;
const ll MAX = 1000;
typedef ll array[MAX][MAX];
const ld E = 1e-11;

set<string> se;

void add(string a, string b){
	for(int i = 0; i < 26; i++){
		se.insert(a + ((char) ('a' + i)) + b);
	}
}

int main() {

	set<string> s;

	string st;
	cin >> st;

	add(st, "");
	add("", st);

	for(int i = 0; i < (int) st.size() - 1; i++)
		add(st.substr(0, i + 1), st.substr(i + 1, st.size() - i - 1));

	cout << se.size() << endl;

}