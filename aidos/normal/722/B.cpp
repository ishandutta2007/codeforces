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
int n;
int p[1111];
string x[1111];
int cnt[1111];
char temp[111];
int ok(char x){
	if(x == 'a') return 1;
	if(x == 'e') return 1;
	if(x == 'i') return 1;
	if(x == 'u') return 1;
	if(x == 'o') return 1;
	if(x == 'y') return 1;
	return 0;
}
void solve(){
	scanf("%d", &n);
	for(int i = 0 ; i < n; i++){
		scanf("%d", &p[i]);
	}
	scanf("\n");
	for(int i = 0; i < n; i++){
		getline(cin, x[i]);
		for(int j = 0; j < x[i].size(); j++){
			if(ok(x[i][j])){
				cnt[i]++;
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(cnt[i] != p[i]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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