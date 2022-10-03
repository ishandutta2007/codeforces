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

ll n, d, ans, tmp;
ll A[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>d;
	for (int i=0; i<n; i++){
		cin>>A[i];
		tmp=i-(lower_bound(A, A+i, A[i]-d)-A)-1;
		ans+=tmp*(tmp+1)/2;
	}
	cout<<ans<<endl;
	return 0;
}