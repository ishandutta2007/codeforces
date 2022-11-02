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
vector<int> g[500100];
vector<int> gr[500100];
int G(int x){
	int sum = 0;
	for(int j = 0; j < 4; j++){
		sum += x % 9;
		x /= 9;
	}
	if(sum > 8) return 0;
	sum = 0;
	for(int j = 0; j < 4; j++){
		sum += x % 9;
		x /= 9;
	}
	return sum <= 8;
}
int BAD(int x){
	int sum = 0;
	for(int j = 0; j < 4; j++){
		sum += x % 9;
		x /= 9;
	}
	sum = 0;
	for(int j = 0; j < 4; j++){
		sum += x % 9;
		x /= 9;
	}
	return sum == 0;
}
vector<int> DD;

void calc(int x){
	vector<int> D;
	int pos = lower_bound(all(DD), x) - DD.begin();
	for(int j = 0; j < 8; j++){
		D.pb(x % 9);
		x /= 9;
	}
	for(int i = 0; i < 4; i++){
		if(D[i] == 0) continue;
		for(int j = 4; j < 8; j++){
			if(D[j] == 0) continue;
			int N = (i + j - 2) % 5;
			D[i]--;
			int d = 0;
			
			for(int h = 3; h >= 0; h--){
				d = d * 9 + D[h];
				if(N == h+1) d++;
			}
			for(int h = 7; h >= 4; h--){
				d = d * 9 + D[h];
			}
			int u = lower_bound(all(DD), d) - DD.begin();
			g[pos].pb(u);
			gr[u].pb(pos);
			D[i]++;
		}
	}
}
int good[500100];
int bad[500100];
int cnt[500500];
int u[500500];
void precalc(){
	int d = 1;
	for(int i = 0; i < 8; i++){
		d *= 9;
	}
	for(int i = 0; i < d; i++){
		if(G(i)) DD.pb(i);
	}
	for(int i = 0; i < DD.size(); i++){
		calc(DD[i]);
	}
	for(int i = 0; i < DD.size(); i++){
		sort(all(g[i]));
		sort(all(gr[i]));
		g[i].resize(unique(all(g[i])) - g[i].begin());
		gr[i].resize(unique(all(gr[i])) - gr[i].begin());
	}

	set<int> S;
	for(int i = 0 ; i< DD.size(); i++){
		if(BAD(DD[i])){
			S.insert(i);
			bad[i] = 1;
			u[i] = 1;
		}
	}
	set<int> L;
	while(S.size()>0 || L.size() > 0){
		if(S.size() > 0){
			int i = *S.begin();
			S.erase(S.begin());
			forit(it, gr[i]){
				if(u[*it]) continue;
				good[*it] = 1;
				L.insert(*it);
				u[*it] = 1;
			}
		}
		else {
			int i = *L.begin();
			L.erase(L.begin());
			forit(it, gr[i]){
				if(u[*it]) continue;
				cnt[*it]++;
				if(cnt[*it] != g[*it].size()) continue;
				bad[*it] = 1;
				S.insert(*it);
				u[*it] = 1;
			}
		}
	}
}
int C[55];
string NAME[2] = {"Alice", "Bob"};
void solve(){
	int tt;
	scanf("%d", &tt);
	for(int i = 0; i < 5; i++){
		C[i] = 0;
	}
	int A = 0;
	for(int i = 0, x; i < 8; i++){
		scanf("%d", &x);
		C[x]++;  
	}
	for(int i = 4; i > 0; i--){
		A = A * 9 + C[i];
	}
	for(int i = 0; i < 5; i++){
		C[i] = 0;
	}
	int B = 0;
	for(int i = 0, x; i < 8; i++){
		scanf("%d", &x);
		C[x]++;
	}
	for(int i = 4; i > 0; i--){
		B = B * 9 + C[i];
	}
	if(tt){
		A = A * 9 *9 * 9*9 + B;
	}else 
		A = B* 9 *9 * 9*9 + A;
	A = lower_bound(all(DD), A) - DD.begin();
	if(bad[A]) printf("%s\n", NAME[tt^1].c_str());
	else if(good[A]) printf("%s\n", NAME[tt].c_str());
	else printf("Deal\n");
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
	precalc();
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}