#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 3e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , step , Rank[LOG][MAXN];
vector<int> vec;
string s;

int cmp(int x , int y){
	if(Rank[step][x] != Rank[step][y])	return Rank[step][x] < Rank[step][y];
	return Rank[step][x ^ (1 << step)] < Rank[step][y ^ (1 << step)];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> s;
	for(int i = 0 ; i < (1 << n) ; i++){
		Rank[0][i] = s[i];
		vec.push_back(i);
	}
	for(int i = 1 ; i <= n ; i++){
		sort(all(vec) , cmp);
		for(int j = 1 ; j < (1 << n) ; j++){
			Rank[i][vec[j]] = Rank[i][vec[j - 1]] + cmp(vec[j - 1] , vec[j]);
		}
		step = i;
	}
	for(int i = 0 ; i < (1 << n) ; i++){
		cout << s[i ^ vec[0]];
	}

    return 0;
}
/*

*/