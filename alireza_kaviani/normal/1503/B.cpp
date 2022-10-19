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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int get(){
	int x; cin >> x;
	return x;
}

void send(int x , int y , int val){
	cout << val << sep << x << sep << y << endl;
}

int n;
vector<pii> v1 , v2;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(i % 2 == j % 2)	v1.push_back({i , j});
			else	v2.push_back({i , j});
		}
	}
	for(int i = 0 ; i < n * n ; i++){
		int x = get();
		if(x != 1 && SZ(v1)){
			send(v1.back().X , v1.back().Y , 1);
			v1.pop_back();
			continue;
		}
		if(x != 2 && SZ(v2)){
			send(v2.back().X , v2.back().Y , 2);
			v2.pop_back();
			continue;
		}
		if(SZ(v1)){
			send(v1.back().X , v1.back().Y , 3);
			v1.pop_back();
		}
		else{
			send(v2.back().X , v2.back().Y , 3);
			v2.pop_back();
		}
	}

    return 0;
}
/*

*/