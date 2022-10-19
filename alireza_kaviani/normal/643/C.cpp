#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

const ll MAXN = 2e5 + 10;
const ll LOG = 52;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , k , pos , A[MAXN] , ps[MAXN];
double ans[MAXN] , s[MAXN] , dp[LOG][MAXN];
vector<pair<ll , pdd>> cht;

ll insect(pdd A , pdd B){
	return ceil((A.Y - B.Y) / (B.X - A.X));
}

void insert(double a , double b){
	while(SZ(cht) && insect(cht.back().Y , {a , b}) <= cht.back().X)	cht.pop_back();
	if(cht.empty())	cht.push_back({-INF , {a , b}});
	else	cht.push_back({insect(cht.back().Y , {a , b}) , {a , b}});
}

double get(ll x){
	pos = min(pos , max(0ll , SZ(cht) - 1));
	while(pos + 1 < SZ(cht) && x >= cht[pos + 1].X)	pos++;
	return cht[pos].Y.X * x + cht[pos].Y.Y;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
		ps[i] = ps[i - 1] + A[i];
		s[i] = s[i - 1] + double(1) / double(A[i]);
		ans[i] = ans[i - 1] + double(ps[i]) / double(A[i]);
	}

	for(int i = 1 ; i <= k ; i++){
		cht = {};	
		insert(-s[n] , -ans[n]);
		for(int j = n ; j >= 1 ; j--){
			dp[i][j] = -ans[j - 1] - get(-ps[j - 1]) + ps[j - 1] * s[j - 1];
			// cout << i << sep << j << sep << dp[i][j] << endl;
			if(i > 1){
				insert(-s[j - 1] , -ans[j - 1] - dp[i - 1][j]);
			}
		}
	}
	printf("%.10f" , dp[k][1]);

    return 0;
}
/*

*/