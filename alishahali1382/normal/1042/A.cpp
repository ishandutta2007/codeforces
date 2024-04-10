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

int n, m, tmp, s, mx, x;
int A[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<n; i++){
		cin>>A[i];
		mx=max(mx, A[i]);
		s+=A[i];
	}
	for (int i=0; i<m; i++){
		A[min_element(A, A+n)-A]++;
		
	}
	cout<<*max_element(A, A+n)<<' '<<mx+m<<endl;
	
	return 0;
}