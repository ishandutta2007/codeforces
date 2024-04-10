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
set<int> st;
vector<int> vec , sec;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		st = {}; vec = {}; sec = {};
		for(int i = 0 ; i < n ; i++){
			cin >> A[i];
			st.insert(i);
		}
		for(int i = 0 ; i < n ; i++){
			if(__gcd(A[i] , A[(i + 1) % n]) == 1)	vec.push_back((i + 1) % n);
		}
		vector<int> ans;
		for(int i = 0 ; i < SZ(vec) ; i++){
	//		cout << i << sep << vec[i] << endl;
			if(st.find(vec[i]) == st.end())	continue;
			st.erase(vec[i]); ans.push_back(vec[i]);
			if(SZ(st) == 0)	 break;
			auto it = st.lower_bound(vec[i]);
			int nxt = (it == st.end() ? (*st.begin()) : (*it));
			int prv = (it == st.begin() ? (*prev(st.end())) : (*prev(it)));
			if(i + 1 < SZ(vec) && vec[i + 1] == nxt)	i++;
			if(__gcd(A[prv] , A[nxt]) == 1)	vec.push_back(nxt);
	//		if(prv == nxt)	break;
	//		cout << nxt << sep << prv << sep << (i + 1 < SZ(vec) ? vec[i + 1] : -1) << endl;
	//		if(i > LOG)	break;
		}
		cout << SZ(ans) << sep;
		for(auto &i : ans)	cout << i + 1 << sep;
		cout << endl;
	}

    return 0;
}
/*

*/