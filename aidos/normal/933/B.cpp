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
ll n, k;
void solve(){
	cin >> n >> k;
	int K = -k;
	vector<int> A;
	for(int i = 0; n > 0;i++){
		if(i&1){
			if(n % k > 0){
				A.pb(k - n % k);
				n += k;
			}else A.pb(0);
		}else{
			A.pb(n % k);
		}
		n/=k;
	}
	cout << A.size() << "\n";
	for(int i = 0; i < A.size(); i++){
		printf("%d ", A[i]);
	}
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