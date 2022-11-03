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
int a[111][111];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	string ans = "Yes";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] == 1) continue;
			int ok = 1;
			for(int s = 0; s < n; s++)
				for(int t=0; t < n; t++){
					if(a[i][s] + a[t][j] == a[i][j]) ok = 0;
				}
			if(ok){
				ans = "No";
			}


		}
	}
	cout << ans << endl;
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