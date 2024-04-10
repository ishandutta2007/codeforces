#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=500000000000000010LL;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 200 * 1000 + 10;

int n, m, d, ans, tmp;
int A[MAXN];

map<int, int> mp;
set<int> st;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>d;
	for (int i=0; i<n; i++){
		cin>>A[i];
		st.insert(A[i]);
	}
	for (; !st.empty(); ans++){
		auto it= st.begin();
		while (it!=st.end()){
			tmp= *it;
			mp[tmp]=ans+1;
			st.erase(it);
			it=st.upper_bound(tmp+d);
		}
	}
	cout<<ans<<endl;
	for (int i=0; i<n; i++) cout<<mp[A[i]]<<' ';
	
	return 0;
}