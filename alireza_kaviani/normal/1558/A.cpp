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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , a , b;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> a >> b;
		vector<int> ans;
		int x = (a + b + 1) / 2 , y = (a + b) / 2;
		for(int i = 0 ; i <= x ; i++){
			int diff = x - i + a - i;
			if(i > a || a - i > y)	continue;
			ans.push_back(diff);
		}
		swap(x , y);
		for(int i = 0 ; i <= x ; i++){
			int diff = x - i + a - i;
			if(i > a || a - i > y)	continue;
			ans.push_back(diff);
		}		
		sort(all(ans));
		ans.resize(unique(all(ans)) - ans.begin());
		cout << SZ(ans) << endl;
		for(int i : ans){
			cout << i << sep;
		}
		cout << endl;
	}

    return 0;
}
/*

*/