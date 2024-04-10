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
string s, t;
void solve(){
	cin >> n >> s >> t;
	
	ll all = 1;
	ll less = 1;
	ll greater = 1;
	ll eq = 1;
	for(int i = 0; i < n; i++) {
		if(s[i] == '?' && t[i] == '?') {
			all = (all * 100) % mod;
			eq = eq * 10 % mod;
			less = less * 55 % mod;
			greater = greater * 55 % mod;
		}else if(s[i] == '?') {
			all = all * 10 % mod;
			eq = eq * 1 % mod;
			less = less * (t[i] - '0' + 1) % mod;
			greater = greater * ('9' - t[i] + 1) % mod;
		}else if(t[i] == '?') {	
			all = all * 10 % mod;
			eq = eq * 1 % mod;
			less = less * ('9' - s[i]+1)  % mod;
			greater = greater * (s[i] - '0' + 1) % mod;
		} else if(s[i] < t[i]){
			greater = 0;
			eq = 0;
		 } else if(t[i] < s[i]) {
		 	less = 0;
		 	eq = 0;
		 } 
	}
	
	cout << ((all - less - greater + eq) % mod + mod) % mod << "\n";
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