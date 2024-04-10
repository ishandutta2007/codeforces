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

ll n , ans , A[MAXN] , S[MAXN] , ps[MAXN];
vector<pair<ll , pll>> cht;

ll insect(pll A , pll B){
	ll x = A.Y - B.Y , y = B.X - A.X;
	return (x / y) + (x % y > 0);
}

void insert(ll a , ll b){
	while(SZ(cht) && insect(cht.back().Y , {a , b}) <= cht.back().X)	cht.pop_back();
	if(SZ(cht) == 0)	cht.push_back({-INF , {a , b}});
	else	cht.push_back({insect(cht.back().Y , {a , b}) , {a , b}});
}

ll get(ll x){
	ll ind = upper_bound(all(cht) , pair<ll , pll>(x , {INF , INF})) - cht.begin() - 1;
	return cht[ind].Y.X * x + cht[ind].Y.Y;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
		ps[i] = ps[i - 1] + A[i];
		S[i] = S[i - 1] + A[i] * i;
	}
	insert(0 , 0);
	for(int i = 1 ; i <= n ; i++){
		ans = max(ans , S[i] + get(-ps[i]));
		insert(i , ps[i] * i - S[i]);
	}
	cout << ans << endl;

    return 0;
}
/*

*/