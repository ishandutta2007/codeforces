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
vector<int> p;

void go(int x){
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0){
			p.pb(i);
			while(x % i == 0) x/=i;
		}
	}
	if(x > 1) p.pb(x);
}

map<int, int> dp;

int get(int mask){
	if(mask == 0) return 0;
	if(dp.count(mask)) return dp[mask];

	int cnt = 0;
	set<int> S, u;
	for(int i = 0; i < 31; i++){
		int g = mask & ((1<<i) - 1);
		int d = mask >> (i + 1);
		if((d|g) != mask){
			//cout << (d|g) << endl; 
			int cc = get(d|g);
			S.insert(cc);
		}
	}
	while(S.count(cnt)) cnt++;
	return dp[mask] = cnt;
}

	
int calc(int x){
	int mask = 0;
	for (int i = 0; i < n; ++i)
	{
		int cnt = 0;
		while(a[i] % x == 0){
			a[i] /= x;
			cnt++;
		}
		if(cnt){
			cnt--;
			mask |= (1<<cnt);
		}
	}
	return get(mask);
}

void solve(){
	//cout << get(3) << endl;
	//return;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++){
		go(a[i]);
	}
	for(int i = 0; i < 100; i++){
		//cout << i << " "<< get(i) << endl;
	}
	sort(all(p));
	int ans = 0;
	for(int i = 0; i < p.size(); i++){
		ans ^= calc(p[i]);
	}
	if(ans) printf("Mojtaba\n");
	else printf("Arpa\n");
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