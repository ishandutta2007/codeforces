#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000;
const int MAXN = 2010;

int n, m, a, ans, k, tmp;
int A[MAXN];
int B[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		A[i]=max(A[i], -A[i]);
	}
	for (int i=1; i<=n; i++){
		int L=0, R=0;
		for (int j=1; j<i; j++) L+=(A[j]<A[i]);
		for (int j=i+1; j<=n; j++) R+=(A[i]>A[j]);
		if (R>L) B[i]=-A[i];
		else B[i]=A[i];
	}
	for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++) ans+=(B[i]>B[j]);
	cout<<ans<<'\n';
	
	return 0;
}