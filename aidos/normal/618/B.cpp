#include <bits/stdc++.h>

using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;

int n, a[55][55];
int used[55];
int p[55];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];	
	for(int i = 1; i <= n; i++){
		int ind = 0;
		for(int k = 0; k<n; k++){
			if(used[k]) continue;
			int cnt = 0;
			for(int j = 0; j < n; j++){
				if(used[j]) continue;
				if(a[k][j] == i) cnt++;
			}
			if(cnt == n - i) ind = k;
		}
		used[ind] = 1;
		p[ind] = i;
	}
	for(int i = 0; i < n; i++)
		cout << p[i] << " ";


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}