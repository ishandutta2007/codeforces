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
set<int> S1, S2, u1, u2;
char c[200200];
void solve(){
	scanf("%d", &n);
	scanf("%s", c);
	for(int i = 0; i < n; i++){
		if(c[i] == 'D')S1.insert(i);
		else S2.insert(i);
	}
	for(int i = 0; i < n + n; i++){
		if(S1.size() == 0 || S2.size() == 0) break;
		u1.clear();
		u2.clear();
		while(S1.size() > 0 || S2.size() > 0){
			if(S1.size() == 0){
				if(u1.size() > 0){
					u1.erase(u1.begin());
				}
				u2.insert(*S2.begin());
				S2.erase(S2.begin());
			}else if(S2.size() == 0){
				if(u2.size() > 0){
					u2.erase(u2.begin());
				}
				u1.insert(*S1.begin());
				S1.erase(S1.begin());
			}else if(*S1.begin() < *S2.begin()){
				S2.erase(S2.begin());
				u1.insert(*S1.begin());
				S1.erase(S1.begin());	
			}
			else{
				S1.erase(S1.begin());
				u2.insert(*S2.begin());
				S2.erase(S2.begin());	
			}
		}
		S1 = u1;
		S2 = u2;
	}
	if(S1.size() > 0) printf("D");
	else printf("R");
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