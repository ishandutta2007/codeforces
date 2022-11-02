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
int a[111];
void solve(){
	int cnt = 0;
	vector<int> g;
	for(int i = 2; i <= 50; i++){
		if(!a[i]){
			for(int j = i + i; j <= 100; j+=i){
				a[j] = 1;
			}
			g.pb(i);
		}
	}
	vector<int> v;
	for(int i = 0; i < g.size(); i++){
		cout << g[i] << endl;
		string x;
		cin >> x;
		if(x == "yes") v.pb(g[i]);
	}
	if(v.size()>1){
		cout << ("composite") << endl;
		return;
	}
	if(v.size() == 0){
		cout << "prime" << endl;
		return;
	}
	if(v[0] * v[0] <= 100){
	cout<< v[0] * v[0] << endl;
		string x;
		cin >> x;
		if(x == "yes") {
			cout << "composite" << endl;
			return;
		}
	}
	cout << "prime" << endl;
		return;
}

int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Test case #%d\n", i);
      solve();
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}