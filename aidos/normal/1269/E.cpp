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

const int inf = (1 << 29) - 1;
const int maxn = (int)2e5 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
int p[maxn];
ll t[2][maxn];
int rp[maxn];
void upd(int id, int pos, int val) {
	for(int i = pos; i <= n; i |= i+1) t[id][i] += val;
}
ll get(int id, int pos) {
	ll res = 0;
	while(pos >= 0) {
		res += t[id][pos];
		pos = (pos&(pos+1)) - 1;
	}
	return res;
}
set<int> s1, s2;
ll inv;
ll add(int p, int k) {
	inv += get(0, n) - get(0, p);
	upd(0, p, 1);
	upd(1, p, p);
	ll ans = inv;
	s2.insert(p);
	s1.insert(*s2.begin());
	s2.erase(s2.begin());
	if(s2.size()+2 <= s1.size()) {
		s2.insert(*(--s1.end()));
		s1.erase(--s1.end());
	}
	ll m = *(--s1.end());
	ll F = s1.size()-1;
	ll S = s2.size();
	ans += F * m - get(1, m-1) - F * (F+1ll)/2;
	ans += get(1, n) - get(1, m) - m * S - S * (S+1ll)/2;
	return ans;
}
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> p[i];
		rp[p[i]] = i;
	}
	for(int i = 1; i <= n; i++) {
		int pos = rp[i];
		cout << add(pos, i) << "\n";
	}

}
int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d: ", i);
      solve();
    }
    
    return 0;
}