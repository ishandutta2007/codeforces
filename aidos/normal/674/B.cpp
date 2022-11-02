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
int n, k;
int a[10];
int used[100100];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> k ;
    for(int i = 0; i < 4; i++){
    	cin >> a[i];
    	used[a[i]] = 1;
    }
	if(k <= n|| n == 4){
		cout << -1 << endl;
		return 0;
	}
	vector < int > g;
	cout << a[0] << " "<< a[2] << " ";
	for(int i = 1; i<= n; i++)
		if(!used[i]) cout << i << " ";
	cout << a[3] << " " << a[1] << endl;

	cout << a[2] << " "<< a[0] << " ";
	for(int i = 1; i<= n; i++)
		if(!used[i]) cout << i << " ";
	cout << a[1] << " " << a[3] << endl;
	

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}