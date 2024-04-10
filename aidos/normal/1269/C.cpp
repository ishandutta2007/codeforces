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
const int maxn = (int)2e3 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m;
string s;
void solve(){
	cin >> n >> m >> s;
	string t;
	for(int i = 0; i < n; i++) {
		t += s[i % m];
	}
	cout << n << "\n";
	if(t >= s) {
		cout << t << "\n";
		return;
	}
	t="";
	int x = m;
	while(x >= 1) {
		x--;
		if(s[x] == '9') {
			s[x] = '0';
			continue;
		}
		s[x]++;
		break;
	}
	for(int i = 0; i < n; i++) {
		t += s[i % m];
	}
	cout << t << "\n";
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