#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 5e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , x , y;
vector<int> A , B , vec[MAXN];
pii mark[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	A.push_back(-1);
	for(int i = 1 ; i <= n ; i++){
		int x;
		cin >> x; A.push_back(x);
		vec[A[i]].push_back(i);
	}
	for(int i = 0 ; i < MAXN ; i++){
		if(SZ(vec[i]) > 1){
			if(x == 0)	x = i;
			else	y = i;
		}
	}
	if(y != 0){
		cout << "YES" << endl;
		cout << vec[x][0] << sep << vec[y][0] << sep << vec[x][1] << sep << vec[y][1] << endl;
		return 0;
	}
	if(SZ(vec[x]) > 3){
		cout << "YES" << endl;
		cout << vec[x][0] << sep << vec[x][1] << sep << vec[x][2] << sep << vec[x][3] << endl;
		return 0;
	}
	n = min(n , 4000);
	for(int i = 1 ; i <= n ; i++){
		for(int j = i + 1 ; j <= n ; j++){
			pii p = mark[A[i] + A[j]];
			if(p.Y == 0){
				mark[A[i] + A[j]] = {i , j};
				continue;
			}
			if(p.X == i || p.X == j || p.Y == i || p.Y == j)	continue;
			cout << "YES" << endl;
			cout << p.X << sep << p.Y << sep << i << sep << j << endl;
			return 0;
		}
	}
	cout << "NO" << endl;

    return 0;
}
/*

*/