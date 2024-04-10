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
int p[100100];
int used[100100];
int b[100100];
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	vector<vector<int> > ans;
	sort(b, b+n);
	map<int, set<int> > M;
	for(int i =0; i < n; i++){
		if(a[i] == b[i]){
			vector<int> v;
			v.pb(i+1);
			ans.pb(v);
		}
		else {
			M[a[i]].insert(i);
		}
	}
	for(int i = 0; i < n; ++i){
		if(a[i] == b[i]) continue;
		if(used[i]) continue;
		int j = i;
		vector<int> v;
		while(!used[j]){
			int nj = *M[b[j]].begin();
			M[b[j]].erase(M[b[j]].begin());
			used[j] = 1;
			v.pb(j+1);
			j = nj;
		}
		ans.pb(v);
	}
	printf("%d\n", (int) ans.size());
	forit(it, ans){
		vector<int>&v = *it;

		printf("%d", (int)v.size());
		forit(it2, v){
			printf(" %d", *it2);
		}
		printf("\n");
	}
	
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