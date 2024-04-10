#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 110;

int n, k;
int A[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=0; i<n; i++) cin>>A[i];
	sort(A, A+n);
	int x=A[n-k];
	int ans=0;
	for (int i=0; i<n; i++){
		if (A[i]>=x && A[i]>0) ans++;
	}
	cout<<ans<<endl;
	
	return 0;
}