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
int dp[1100];
int a[111];


int get(int i){
	if(i == n) return 0;
	int &res = dp[i];
	if(res != -1) return res;
	res = get(i+1);
	int sum = 0;
	for(int j = i+1; j < n; j++)
		sum += a[j];
	res = max(res, sum - get(i+1) + a[i]);
	return res;
}
void solve(){

	cin >> n;
	memset(dp, -1, sizeof dp);
	int sum = 0;
	for(int i = 0; i < n; i++)
		cin>>a[i];
	for(int i = 0; i < n; i++){
		sum += a[i];
	}
	cout << sum - get(0) << " "<< get(0) << endl;
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