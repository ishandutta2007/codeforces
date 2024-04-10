#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef int ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 4e3 + 10;
const ll Inf = 1e9;
const ll Log = 30;

ll dp[N][N];
ll mn[N][N];
ll mn2[N][N];

int la[N][30];
int lb[N][30];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int ti, td, tr, te;
	cin >> ti >> td >> tr >> te;
	str s, t;
	cin >> s >> t;
	int n, m;
	n = s.size();
	m = t.size();
	s = '#' + s;
	t = '!' + t;

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 26; j++) la[i][j] = la[i - 1][j];
		la[i][s[i] - 'a'] = i;
	}

	for(int i = 1; i <= m; i++){
		for(int j = 0; j < 26; j++) lb[i][j] = lb[i - 1][j];
		lb[i][t[i] - 'a'] = i;
	}
	memset(dp, 31, sizeof dp);
	memset(mn, 31, sizeof mn);
	memset(mn2, 31, sizeof mn2);
	
	dp[0][0] = 0;
	//int mn;
	mn[0][0] = -(2 * td);
	mn2[0][0] = -(2 * ti);
	for(int j = 0; j <= m; j++){
		//mn = Inf;
		for(int i = 0; i <= n; i++){
			if(i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + td);
			if(j) dp[i][j] = min(dp[i][j], dp[i][j - 1] + ti);
			if(i && j) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i] == t[j] ? 0 : tr));
			
			//cerr << mn << " " << te << " " << (s[i] == t[j - 1] ? 0 : tr) << " " << i*td << '\n';
			if(i >= 2 && j >= 2){
				ll C = 0;
				ll idx = lb[j - 1][s[i] - 'a'];
				if(idx){
					C += ti * (j - idx - 1);
					dp[i][j] = min(dp[i][j], mn[i - 2][idx - 1] + te + tr + C + i*td);
				}
			}
			if(i)
				mn[i][j] = min(mn[i - 1][j], dp[i][j] - ((i + 2) * td));
			
			if(i >= 2 && j >= 2){
				ll C = 0;
				ll idx = la[i - 1][t[j] - 'a'];
				if(idx){
					C += td * (i - idx - 1);
					dp[i][j] = min(dp[i][j], mn2[idx - 1][j - 2] + te + tr + C + j*ti);
				}
			}
			if(j)
				mn2[i][j] = min(mn2[i][j - 1], dp[i][j] - ((j + 2) * ti));
			if(i >= 2 && j >= 2){
				ll C = 0;
				ll idx = lb[j - 1][s[i] - 'a'];
				ll idx2 = la[i - 1][t[j] - 'a'];
				if(idx && idx2){
					C += ti * (j - idx - 1);
					C += td * (i - idx2 - 1);
					dp[i][j] = min(dp[i][j], dp[idx2 - 1][idx - 1] + te + C);
				}
			}
			
		}
	}
	cout << dp[n][m];
	return 0;
}