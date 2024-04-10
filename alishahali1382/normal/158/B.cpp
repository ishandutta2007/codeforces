#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 120 * 1000 + 10;

int n, tmp;
int A[5];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>tmp;
		A[tmp]++;
	}
	int ans=A[4]+A[3];
	A[1]-=min(A[1], A[3]);
	ans+=A[2]/2;
	A[2]%=2;
	ans+=(A[2]*2+A[1]+3)/4;

	cout<<ans<<endl;
	return 0;
}