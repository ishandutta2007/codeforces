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

int a[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int get(string x){
	if(x[0] == 'm') return 0;
	if(x[0] == 't' && x[1] == 'u') return 1;
	if(x[0] == 'w') return 2;
	if(x[0] == 't') return 3;
	if(x[0] == 'f') return 4;
	if(x[0] == 's' && x[1] == 'a') return 5;
	if(x[0] == 's' && x[1] == 'u') return 6;
}
void solve(){
	string s, t;
	cin >> s >> t;
	int x = get(s);
	int y = get(t);
	for(int i  = 0; i < 11; i++){
		if((x + a[i]) % 7 == y){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}