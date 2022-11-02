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

char c[100100];
string s, t;
void solve(){
	scanf("%s", c);
	int n = strlen(c);
	for(int i = 0; i < n; i++){
		if(c[i] != 'a') t += c[i];
	}
	int m = t.size();
	if(m % 2 == 1) {
		cout << ":(\n";
		return;
	}
	for(int i = 0; i < m/2; i++) if(t[i] != t[i + m/2] || c[n-i-1] == 'a') {
		cout << ":(\n";
		return;
	}
	for(int i = 0; i < n-m/2; i++) printf("%c", c[i]);
	printf("\n");
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