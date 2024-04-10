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

int q , n , m , x , H[MAXN] , tot[MAXN];
set<pii> st;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> m >> x; st.clear();
		fill(tot , tot + m + 5 , 0);
		cout << "YES" << endl;
		for(int i = 1 ; i <= m ; i++)	st.insert({tot[i] , i});
		for(int i = 1 ; i <= n ; i++){
			cin >> H[i];
			pii A = (*st.begin());
			st.erase(st.begin());
			tot[A.Y] += H[i];
			st.insert({tot[A.Y] , A.Y});
			cout << A.Y << sep;
		}
		cout << endl;
	}

    return 0;
}
/*

*/