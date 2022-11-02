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
#include <bitset>
#include <unordered_map>

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

const int inf = 100100;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
char c[200200];
int a[200200];
bool check(char x) {
	int la = -1, fi = n;
	for(int i = 0; i < n; i++) {
		if(c[i] < x) a[i] = 1;
		else if(c[i] == x) a[i] = 0;
		else a[i] = 2;
		if(a[i] == 1) la = i;
		if(a[i] == 2) fi = min(fi, i);
	}
	int mx = 0;
	for(int i = la+1; i < n; i++) if(a[i] == 0) a[i] = 1;
	for(int i = 0; i < fi; i++) if(a[i] == 0) a[i] = 2;
	for(int i = 0; i < n; i++) {
		if(a[i] == 0) {
			return false;
		}
	}
	string s, t;
	for(int i = 0; i < n; i++) if(a[i] == 1) s += c[i]; else t += c[i];
	s += t;
	for(int i = 1; i < n; i++) if(s[i] < s[i-1]) return false;
	for(int i = 0; i < n; i++) printf("%d", a[i]);
	printf("\n");
	return true;
}
void solve(){
	scanf("%d%s", &n, c);
	for(char x = '0'; x <= '9'; x++) {
		if(check(x)) {
			return;
		}
	}
	cout << "-\n";
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