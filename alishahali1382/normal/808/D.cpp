#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 100010;

int n, m, tmp;
ll s;
ll A[MAXN];

set<ll> st;
map<ll, int> mp; 

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%lld", &A[i]);
		mp[A[i]]++;
		s+=A[i];
	}
	if (s%2){
		cout<<"NO"<<endl;
		return 0;
	}
	s/=2;
	for (int i=0; i<n; i++){
		s-=A[i];
		mp[A[i]]--;
		if (!s || st.find(-s)!=st.end() || mp[s]){
			cout<<"YES"<<endl;
			return 0;
		}
		st.insert(A[i]);
	}
	
	
	cout<<"NO"<<endl;
	return 0;
}