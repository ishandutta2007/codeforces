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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , ax , ay , x , y;
vector<pair<pll , ll>> vec[3][3];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> ax >> ay;
	for(int i = 0 ; i < n ; i++){
		string s;
		cin >> s >> x >> y;
		x -= ax; y -= ay;
		if(x != 0 && y != 0 && x != y && x != -y){
			continue;
		}
		ll px = -1 , py = -1 , type = 0;
		if(x < 0)		px = 0;
		else if(x == 0)	px = 1;
		else			px = 2;
		if(y < 0)		py = 0;
		else if(y == 0)	py = 1;
		else			py = 2;
		if(s == "B")	type = 0;
		if(s == "R")	type = 1;
		if(s == "Q")	type = 2;
		vec[px][py].push_back({{abs(x) , abs(y)} , type});
//		cout << x << sep << y << sep << px << sep << py << endl;
	}
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			sort(all(vec[i][j]));
			if(SZ(vec[i][j]) == 0)	continue;
			int type = vec[i][j][0].Y;
			if(type == 2){
				return cout << "YES" << endl , 0;
			}
			if((i == 1 || j == 1) && type == 1){
				return cout << "YES" << endl , 0;
			}
			if(i != 1 && j != 1 && type == 0){
				return cout << "YES" << endl , 0;
			}
		}
	}
	cout << "NO" << endl;

    return 0;
}
/*

*/