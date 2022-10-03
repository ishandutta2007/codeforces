#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 100010;

ll n, ans=1, s, x;
int A[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>s;
		A[s]=i;
	}
	//for (int i=1; i<=n; i++) cerr<<A[i]<<' ';cerr<<endl;
	s=x=0;
	for (int i=1; i<=n; i++){
		if (x<A[i]) ans=max(ans, ++s);
		else s=1;
		x=A[i];
	}
	cout<<n-ans<<endl;
	return 0;
}