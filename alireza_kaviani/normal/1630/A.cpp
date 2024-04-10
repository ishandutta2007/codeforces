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

int q , n , k , mark[MAXN];

void add(int x , int y){
	if(mark[x] || mark[y])	return;
	mark[x] = mark[y] = 1;
	cout << x << sep << y << endl;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> k;
		fill(mark , mark + n , 0);
		if(n == 4 && k == 3){
			cout << -1 << endl;
			continue;
		}
		if(k == n - 1){
			add(n - 2 , n - 1);
			add(0 , 1);
			add(2 , n - 4);
			add(3 , n - 3);
			for(int i = 0 ; i < n ; i++){
				add(i , (n - 1) ^ i);
			}
			continue;
		}
		add(k , n - 1);
		add(0 , (k) ^ (n - 1));
		for(int i = 0 ; i < n ; i++){
			add(i , (n - 1) ^ i);
		}
	}

    return 0;
}
/*

*/