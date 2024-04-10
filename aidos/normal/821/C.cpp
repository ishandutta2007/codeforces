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
set<int> S;
vector<int> V;
char com[1111];
void solve(){
	scanf("%d", &n);
	int cur = 1;
	int cnt = 0;
	for(int i = 0, x; i < 2 * n; i++){
		scanf("%s", com);
		if(com[0] == 'a'){
			scanf("%d", &x);
			V.pb(x);
		}
		else {
			if(V.size() == 0){
				S.erase(cur);
			}else if(V.back() == cur){
				V.pop_back();
			}
			else {
				for(int j = 0; j < V.size(); j++){
					S.insert(V[j]);
				}
				V.clear();
				cnt++;
				S.erase(cur);
			}
			cur++;
		}
	}
	cout << cnt << endl;
}

int main () {
    //cout << "Hello world\n";
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}