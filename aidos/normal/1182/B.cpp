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

const int inf = (1ll << 25) - 1;
const int maxn = (int) 500 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
char s[maxn][maxn];
int n, m;
void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	vector<int> x, y;

	for(int i = 1; i + 1 < n; i++) {
		for(int j = 1; j + 1 < m; j++) {
			int cnt = 0;
			for(int t1 = -1; t1 <= 1; t1++) {
				for(int t2 = -1; t2 <= 1; t2++) {
					if(abs(t1 * t2) != 1) {
						if(s[t1+i][t2+j] == '*') cnt++;
					}
				}
			}
			if(cnt == 5) {
				x.push_back(i);
				y.push_back(j);
			}
		}
	}
	if(x.size() != 1) {
		cout << "NO\n";
		return;
	}
	int a = x[0], b = y[0];
	for(int i = 0; true; i++) {
		if(a >= 0 && s[a][b] == '*') s[a][b] = '.';
		else break;
		a--;
	}
	a = x[0], b = y[0];
	s[a][b] = '*';
	for(int i = 0; true; i++) {
		if(a < n && s[a][b] == '*') s[a][b] = '.';
		else break;
		a++;
	}
	a = x[0], b = y[0];
	s[a][b] = '*';
	for(int i = 0; true; i++) {
		if(b < m && s[a][b] == '*') s[a][b] = '.';
		else break;
		b++;
	}
	a = x[0], b = y[0];
	s[a][b] = '*';
	for(int i = 0; true; i++) {
		if(b >=0 && s[a][b] == '*') s[a][b] = '.';
		else break;
		b--;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			
			if(s[i][j] == '*'){
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}

int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }
    
    return 0;
}