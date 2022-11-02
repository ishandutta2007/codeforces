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
int a[100100];
int b[100100];
ll sumA, sumB, curA, curB;
int used[100100];

bool cmpA(int i,int j){
	return a[i] > a[j];
}
bool cmpB(int i,int j){
	return b[i] > b[j];
}

void printans(){
	vector<int> x;
	for(int i = 0 ; i< n; i++)
		if(used[i]) x.pb(i);
	//assert(x.size() <= n/2 + 1);
	printf("%d\n", (int) x.size());
	for(int i = 0; i < x.size(); i++){
		if(i) printf(" ");
		printf("%d", x[i] + 1);
	}
	printf("\n");
	exit(0);
}
void solve(){
	scanf("%d", &n);
	set<pii> SA, SB;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		SA.insert(mp(a[i], i));
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
		SB.insert(mp(b[i], i));
	}
	int lim = (n/2) + 1;
	int la = -1;
	for( ; SB.size() > 0 && lim > 0; ){
		lim--;
		int id = (--SB.end())->s;
		used[id] = 1;
		SB.erase(mp(b[id], id));
		SA.erase(mp(a[id], id));
		if(SA.size() > 0){
			id = SA.begin()->s;
			la = id;
			SB.erase(mp(b[id], id));
			SA.erase(mp(a[id], id));
		}
	}
	if(lim) used[la] = 1;
	
	printans();
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