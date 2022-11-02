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

int a[100100];
vector<int> v;
int used[100100];
int nxt[100100];
int val[100100];
int p[100100];
int n, d, x;
int lim = 700;
int cnt = 0;
void ask(int ind){
	cout << "? " << ind + 1 << endl;
	cin >> val[ind] >> nxt[ind];
	cnt++;
}

void solve(){
	srand(time(NULL));
	cin >> n >> d >> x;
	for(int i = 0; i < n; i++){
		p[i] = i;
	}
	random_shuffle(p, p + n);
	int prev = -1;
	int ans = inf;
	int i;
	for(i = 0; i < n && i < lim; i++){
		ask(p[i]);
		if(val[p[i]] >= x) ans = min(ans, val[p[i]]);
		if(val[p[i]] > x) continue;
		if(prev == -1 || val[prev] < val[p[i]]) prev = p[i];

	}
	int st = prev;
	if(prev == -1){
		prev = d-1;
	}else prev = nxt[prev]-1;

	while(cnt < min(1999, n) && prev != -2){
		ask(prev);
		if(val[prev] >= x) ans = min(ans, val[prev]);
		prev=nxt[prev]-1;
	}
	if(ans == inf) ans = -1;
	cout << "! " << ans << endl;
}

int main () {
    //cout << "Hello world\n";
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}