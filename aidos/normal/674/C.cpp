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


double dp[200200][55];
int opt[200200][55];
ll sum[200200];
int a[200200];
double rev_sum[200200];

double rev_sum2[200200];
int n, k;
vector < pair < double, double> > dd[55];
double inter(pair < double, double> a,  pair < double, double> b) {
  return (a.f - b.f) / (b.s - a.s);
}
bool ok(pair < double, double> a, pair < double, double> b, pair < double, double> c){
	if(inter(a, c)  > inter(b, c)) return 1;
	return 0;
}

void add(vector < pair < double, double> > &cur,  pair<double, double> x){
	while (cur.size() > 1 && ok(cur[cur.size() - 2], cur[cur.size() - 1], x))
    	cur.pop_back();
	cur.push_back(x);
}

double get(vector < pair < double, double> > &cur,  double x){
	 int l = 0, r = (int) cur.size() - 1;
  	while (r - l > 1) {
    int mid = (l + r) / 2;
    if (inter(cur[mid], cur[mid + 1]) < x) 
      l = mid;
    else
      r = mid;
 	 }
	double ans = 1e18;
  for (int i = l; i <= r; i++)
    ans = min(ans, cur[i].s * x + cur[i].f);
  return ans;	
}



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
    	scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + a[i];
		rev_sum[i] = rev_sum[i-1] + ((1.0 * sum[i])/a[i]);
		rev_sum2[i] = rev_sum2[i-1] + ((1.0)/a[i]);
	}
	
	for(int i = 1; i <= n; i++){
		
		for(int j = min(k, i); j >= 1; j--){
			if(j == 1){
				dp[i][j] = rev_sum[i];
			}
			else dp[i][j] = rev_sum[i] + get(dd[j-1], rev_sum2[i]) ;
			double cns = rev_sum2[i]* sum[i] + dp[i][j] - rev_sum[i];
			double cns2 = -sum[i];
			add(dd[j], mp(cns, cns2));
		}
		
	}
	printf("%.12f\n", (double) dp[n][k]);
	
	

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}