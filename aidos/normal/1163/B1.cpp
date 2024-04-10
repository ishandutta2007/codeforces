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
int n;
int a[100100];
int cnt[100100];
int t[100100];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	map<int, int> M;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		cnt[a[i]]++;
		if(cnt[a[i]] > 1) {
			M[cnt[a[i]] - 1]--;
			if(M[cnt[a[i]] - 1] == 0) M.erase(cnt[a[i]]-1);
		}
		M[cnt[a[i]]]++;
		if(M.size() == 1) {
			if(M.begin()->f==1 || M.begin()->s==1) ans = i+1;
		}else if(M.size() == 2) {
			if(M.begin()->f==1 && M.begin()->s==1) ans = i+1;
			else if((--M.end())->s == 1 && ((--M.end())->f==M.begin()->f+1)) ans = i+1;
		}
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