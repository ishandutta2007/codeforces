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

using namespace std;
map < pii, int > mm;
int n;
int a[111];
int get(char c){
	if(c == '>') return 1;
	if(c == '=') return 0;
	return -1;
}
int cnt = 0;
int ask(int x, int y){
	if(mm.count(mp(x, y))) return mm[mp(x, y)];
	cout << "? " << x << " "<<y << endl;

	string ans = "";

	
	if(a[x] < a[y]) ans = "<";
	else if(a[x] == a[y]) ans = ">";
	else ans = "=";
	cin >> ans;
	cnt++;
	mm[mp(x, y)] = get(ans[0]);
	mm[mp(y, x)] = get(ans[0]) * -1;
	return get(ans[0]);
}

pii rec(int l, int r){
	if(l == r){
		return mp(l, l);
	}
	int mid = (l + r)>>1;
	if((r-l+1) % 2 == 0) {
		if((r-l+1) > 2 && (r - mid) % 2 == 1) mid++;
	}
	pii c1 = rec(l, mid);
	pii c2 = rec(mid+1, r);
	if(ask(c1.f, c2.f) > 0) c1.f = c2.f;
	if(ask(c1.s, c2.s) < 0) c1.s = c2.s;
	return c1;
}
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		a[i] = i;
	}
	mm.clear();
	cnt = 0;
	pii xx = rec(1, n);
	cout << "! "<<xx.f << " " << xx.s << endl;
	//cout << (3 * n + 1)/2 - 2 << endl;
	//cout << cnt << endl;
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