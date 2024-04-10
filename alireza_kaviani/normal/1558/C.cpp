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

int q , n , A[MAXN];

int Find(int x){
	for(int i = 1 ; i <= n ; i++){
		if(A[i] == x){
			return i;
		}
	}
	return -1;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		int flag = 0;
		for(int i = 1 ; i <= n ; i++){
			cin >> A[i];
			if(A[i] % 2 != i % 2)	flag = 1;
		}
		if(flag){
			cout << -1 << endl;
			continue;
		}
		vector<int> ans;
		for(int i = n ; i > 1 ; i -= 2){
			int pos = Find(i);
			reverse(A + 1 , A + pos + 1);
			ans.push_back(pos);
			pos = Find(i - 1);
			reverse(A + 1 , A + pos);
			ans.push_back(pos - 1);
			reverse(A + 1 , A + pos + 2);
			ans.push_back(pos + 1);
			reverse(A + 1 , A + 4);
			ans.push_back(3);
			reverse(A + 1 , A + i + 1);
			ans.push_back(i);
		}
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