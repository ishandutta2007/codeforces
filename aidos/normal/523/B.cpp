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
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

long double d[200100];
long double sum[200100];
double c;
int T;
double a[200100];
int n;
int m;



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> n >> T >> c;
    for(int i = 0 ; i<n; i++){
    	cin >> a[i];
	}
	
	//for(int i = 0; i < n; ++i)
	//	cout << a[i] << endl;

	for(int i = 0 ;i < n; i++)
		a[i] /= (1.0 * T);

	//for(int i = 0; i < n; ++i)
	//	cout << a[i] << endl;
	d[0] = 0;
	sum[0] = 0;
	for(int i = 0; i < n; i++){
		sum[i+1] = sum[i] + (long double)a[i];
		d[i+1] = (d[i] + a[i])/c;
	}
	/*for(int i = 0;i <= n; i++)
		cout << sum[i] << endl;
	
	for(int i = 0;i <= n; i++)
		cout << d[i] << endl;
	*/
	scanf("%d", &m);
	for(int i = 0, p; i < m; i++){
		scanf("%d", &p);
		double x = (double) d[p];
		double y = (double) (sum[p] - sum[p-T]);
		//cout << x << " "<< y << endl;

		double di = 1.0 - x/y;
		if(di < 0) di = -di;
		printf("%.9f %.9f %.9f\n", y, x, di);
	}



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}