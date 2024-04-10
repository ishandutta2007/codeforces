#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000000;
const int mod = 998244353;
const int MAXN = 200010;

int n, k, a, cnt, x, tmp, m;

set<int> st;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k>>a>>m;
	a++;
	cnt=(n+1)/a;
	st.insert(0);
	st.insert(n+1);
	for (int i=1; i<=m; i++){
		cin>>x;
		auto it=st.lower_bound(x);
		tmp=(*it)-*(--it);
		it++;
		cnt-=tmp/a;
		cnt+=(*it-x)/a+(x-*(--it))/a;
		it++;
		st.insert(x);
		if (cnt<k){
			cout<<i<<endl;
			return 0;
		}
	}
	//cerr<<cnt<<endl;
	cout<<-1<<endl;
	return 0;
}