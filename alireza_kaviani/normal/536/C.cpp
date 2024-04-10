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
const double eps = 1e-15;

int n , s[MAXN] , r[MAXN];
vector<pair<pii , int>> vec;
vector<pair<double , int>> cht;

double insect(int i , int j){
	double x = 1.0 / r[i] - 1.0 / r[j] , y = 1.0 / s[j] - 1.0 / s[i];
	if(s[i] == s[j])	return (r[i] < r[j] ? -INF : INF);
	// cout << i << sep << j << sep << x << sep << y << sep << x / y << endl;
	return x / y;
}

void insert(int i){
	while(SZ(cht) && insect(cht.back().Y , i) <= max(0.0 , cht.back().X - eps))	cht.pop_back();
	if(SZ(cht) == 0)	cht.push_back({0 , i});
	else if(s[cht.back().Y] == s[i])	cht.push_back({cht.back().X , i});
	else	cht.push_back({insect(cht.back().Y , i) , i});
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> s[i] >> r[i];
		vec.push_back({{s[i] , r[i]} , i});
	}
	sort(all(vec));
	for(pair<pii , int> i : vec){
		insert(i.Y);
	}
	vector<int> ans;
	for(int i = 0 ; i < SZ(cht) ; i++){
		ans.push_back(cht[i].Y);
	}
	sort(all(ans));
	for(int i : ans)	cout << i << sep;

    return 0;
}
/*

*/