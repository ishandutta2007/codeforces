#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 998244353;
const int MAXN = 2000010;

ll n, m, k;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (k*(k-1)<2*m) k++;
	cout<<max(0LL, n-2*m)<<' '<<max(0LL, n-k)<<endl;
	
	return 0;
}