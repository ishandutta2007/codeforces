#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
void solve(){
	string s;
	cin >> s;
	sort(all(s));
	int cnt = 0;
	vector<string> v;
	string x = "";
	x += s[0];
	for(int i = 1; i < s.size(); i++) {
		if(s[i] != s[i-1]) {
			v.pb(x);
			x = "";
		}
		x += s[i];
	}
	v.pb(x);
	if(v.size() == 1) {
		cout << s << "\n";
		return;
	}
	string A = "";
	if(v.size() > 3) {
		A = v[2] + v[0] + v[3] + v[1];
		for(int i = 4; i < v.size(); i++) {
			if(i % 2 == 0) A += v[i];
			else A = v[i] + A;
		}
		cout << A << "\n";
		return;
	}
	if(v.size() == 2) {
		if(v[1][0] - v[0][0] == 1) {
			cout << "No answer\n";
			return;
		}
		cout << s << "\n";
		return;
	}
	
	if(v[1][0] - v[0][0] == 1 && v[2][0] - v[1][0] == 1) {
		cout << "No answer\n";
		return;
	}
	
	if(v[1][0] - v[0][0] != 1 && v[2][0] - v[1][0] != 1) {
		cout << s << "\n";
		return;
	}
	if(v[1][0] - v[0][0] == 1) cout << v[0] << v[2] << v[1] << "\n";
	else cout << v[1] << v[0] << v[2] << "\n";
}

int main () {
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}