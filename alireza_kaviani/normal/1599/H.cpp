#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
//#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int dist;

int query(int x , int y){
	cout << "? " << x << sep << y << endl;
	int ans; cin >> ans;
	return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	dist = query(1 , 1);
	int l = 1 , r = INF;
	while(r - l > 1){
		int mid = l + r >> 1;
		int dist2 = query(1 , mid);
		if(dist2 + mid - 1 == dist)	l = mid;
		else	r = mid;
	}
	int x1 = dist - l + 2 , y1 = l;
	int x2 = INF - query(INF , y1);
	int y2 = INF - query(x1 , INF);
	cout << "! " << x1 << sep << y1 << sep << x2 << sep << y2 << endl;

    return 0;
}
/*

*/