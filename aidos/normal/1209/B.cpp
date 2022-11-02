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
string s;
int a[1111], b[1111];
int ans = 0;
void solve(){
	cin >> n >> s;
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
	for(int i = 0;i < 5000; i++) {
		for(int j = 0; j < n; j++){
			if(b[j] <= i && (i-b[j]) % a[j] == 0) {
				int t = s[j] - '0';
				s[j] = 1-t+'0';
			}
		}
		int cnt = 0;
		for(int j = 0; j < n; j++) cnt+=s[j] == '1';
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
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