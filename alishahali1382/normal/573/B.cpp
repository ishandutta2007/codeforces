#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 1000010;

int n, ans, t, cnt;
int A[MAXN];
int L[MAXN];
int R[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++) L[i]=min(L[i-1]+1, A[i]);
	for (int i=n; i; i--) R[i]=min(R[i+1]+1, A[i]);
	for (int i=1; i<=n; i++) ans=max(ans, min(A[i], min(L[i], R[i])));
	cout<<ans<<endl;
	return 0;
}