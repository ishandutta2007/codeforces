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

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , m , mark[MAXN];
vector<int> vec;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		int x; cin >> x;
		if(x < MAXN){
			mark[x] = 1;
		}
	}
	for(int i = 1 ; i < MAXN ; i++){
		if(mark[i])	continue;
		if(i > m)	break;
		m -= i;
		vec.push_back(i);
	}
	cout << SZ(vec) << endl;
	for(int i : vec)	cout << i << sep;

    return 0;
}
/*

*/