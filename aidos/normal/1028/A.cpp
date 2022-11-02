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
int n, m;
string s[1111];
void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> s[i];
	int x = 0, y = 0;
	set<int> Sx, Sy;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(s[i][j] == 'B'){
				Sx.insert(i);
				Sy.insert(j);
			}
		}
	}
	cout << (*(--Sx.end()) + *Sx.begin())/2 + 1 << " ";
	
	cout << (*(--Sy.end()) + *Sy.begin())/2 + 1 << "\n";
	
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