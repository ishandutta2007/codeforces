#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=200 * 1000 + 10;

ll n, s, ans, m;
ll A[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>s;
	for (int i=0; i<n; i++) cin>>A[i];
	sort(A, A+n);
	m=n/2;
	for (int i=0; i<m; i++){
		if (A[i]>s){
			ans+=A[i]-s;
		}
	}
	if (A[m]<s) ans+=s-A[m];
	if (A[m]>s) ans+=A[m]-s;
	for (int i=m+1; i<n; i++){
		if (A[i]<s){
			ans+=s-A[i];
		}
	}
	cout<<ans<<endl;
	
	return 0;
}