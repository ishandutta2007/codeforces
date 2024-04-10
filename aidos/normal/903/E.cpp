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
int n, k;
string s[5555];
int good = 1;
int cnt[5555];

int ok(int l, int r){
	for(int i = 1; i < k; i++){
		int cc = cnt[i];
		if(s[0][l] != s[i][l]) cc--;
		if(s[0][r] != s[i][r]) cc--;
		if(s[0][l] != s[i][r]) cc++;
		if(s[0][r] != s[i][l]) cc++;
		if(cc == 2) continue;
		if(cc == 0 && good) continue;
		return 0;
	}
	return 1;
}

void solve(){
	cin >> k >> n;
	set<char>S;
	for(int i = 0;  i<k; i++){
		cin >> s[i];
	}
	set<string> C;
	for(int i = 0; i < n; i++){
		S.insert(s[0][i]);
	}
	for(int i = 0; i < k; i++){
		string t =s[i];
		sort(all(t));
		C.insert(t);
	}
	if(C.size() != 1){
		cout << -1 << endl;
		return;
	}
	if(k == 1){
		swap(s[0][n-1], s[0][0]);
		cout << s[0]<<endl;
		return;
	}
	
	if(S.size() == n) good = 0;
	for(int i = 1; i < k; i++){
		for(int j = 0; j < n; j++){
			if(s[0][j] != s[i][j]) cnt[i]++;
		}
	};
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(ok(i, j)){
				swap(s[0][i], s[0][j]);
				cout << s[0] << endl;
				return;
			}
		}
	}
	cout << -1<<endl;
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