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
#include <bitset>
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
int m;
int a[35];
int C;
vector<int> ans;
int games[444];


int ta[422][422];
int dp[34][77][77 * 77];
int cp[34][77][77*77];

bool check(int n){
	for(int i=0; i <= n; i++)
		for(int j =0; j <= n * (n-1)/2; j++)
			dp[m][i][j]= 0;
	dp[m][0][n * (n-1)/2] = 1;
	for(int i = m-1; i >=0; i--){
		for(int ii = 0; ii <= n; ii++)
			for(int j = 0; j <= n * (n-1)/2; j++){
				dp[i][ii][j] = 0;
			}
		for(int cnt = 0; cnt <= n; cnt++){
			for(int d = n * (n-1)/2; d >= 0; d--){
				int good = dp[i + 1][cnt][d];
				int sum = (n - 1 + (n-cnt)) * cnt/2;
			    for(int cc = 1; cc + cnt <= n && cc * a[i] <= d; cc++){
			    	sum += n-cc-cnt;
			    	if(sum < n * (n-1)/2 - d + cc * a[i]) good = 0;
					if(good){
						dp[i][cc + cnt][d - cc * a[i]] = 1;
						cp[i][cc+cnt][d-cc*a[i]] = cc;
					}
				}
			}
		}
	}
	return dp[0][n][0];
}
int n;
void go(int pos, int sum, int cnt){
	if(pos == m) return;
	int cc = cp[pos][cnt][sum];
	for(int i = 0; i< cc;i++)
		ans.pb(a[pos]);
	go(pos+1, sum + cc * a[pos], cnt - cc);
}
void solve(){
	scanf("%d", &m);
	int sum = 0;
	int mx = m;
	for(int i = 0; i < m; i++){
		scanf("%d", &a[i]);
		mx = max(mx, a[i]+1);
		sum += a[i];
	}
	sort(a, a + m);

	int found = 0;
	C++;

	for(int i = mx; i < 77; i++){
		if(check(i)){
			found = i;
			break;
		}
	}
	if(!found){
		printf("=(");
		return;
	}
	n = found;
	go(0, 0, n);
	sort(all(ans));

	for(int i = 0; i < n; i++){
		games[i] = n-ans[i]-1;
	}
	for(int i=n-1; i >=0; i--){
		int cur = ans[i];
		vector<pii> d;
		for(int j = n-1; cur > 0 && j > i; j--){
			if(!ta[i][j]){
				ta[i][j] = 1;
				ta[j][i] = 2;
				cur--;
			}
		}
		for(int j = 0; j < i; j++){
			if(games[j] > 0)
			   d.pb(mp(-games[j], j));
		}
		sort(all(d));
		for(int j = 0; j < d.size() && cur > 0; j++){
			int k = d[j].s;
			if(!ta[i][k]){
				games[k]--;
				ta[i][k] = 1;
				ta[k][i] = 2;
				cur--;
			}
		}

		//cout << cur << endl;
	}
	printf("%d\n", n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d", ta[i][j] % 2);
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