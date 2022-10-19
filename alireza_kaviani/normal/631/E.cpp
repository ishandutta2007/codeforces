#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , val , ans , A[MAXN] , ps[MAXN];
vector<pair<ll , pll>> cht;

ll insect(pll A , pll B){
	ll x = A.Y - B.Y , y = B.X - A.X;
	return x / y + (x % y > 0);
}

void insert(ll a , ll b){
	while(SZ(cht) && insect(cht.back().Y , {a , b}) <= cht.back().X)	cht.pop_back();
	if(cht.empty())	cht.push_back({-INF , {a , b}});
	else	cht.push_back({insect(cht.back().Y , {a , b}) , {a , b}});
}

ll get(ll x){
	ll ind = lower_bound(all(cht) , pair<ll , pll>(x , {INF , INF})) - cht.begin() - 1;
	return cht[ind].Y.X * x + cht[ind].Y.Y;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
		ps[i] = ps[i - 1] + A[i];
		val += A[i] * i;
	}
	// cout << val << endl;
	for(int i = n ; i >= 1 ; i--){
		insert(-i , -ps[i]);
		ans = max(ans , get(-A[i]) - A[i] * i + ps[i]);
		// cout << i << sep << get(-A[i]) - A[i] * i + ps[i] << endl;
	}
	cht = {};
	for(int i = 1 ; i <= n ; i++){
		insert(i , -ps[i - 1]);
		ans = max(ans , get(A[i]) - A[i] * i + ps[i - 1]);
	}
	cout << ans + val << endl;


    return 0;
}
/*

*/