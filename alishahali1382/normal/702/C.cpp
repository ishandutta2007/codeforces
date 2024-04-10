#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=100 * 1000 + 10;

int n, m;
int A[MAXN];
int B[MAXN];

ll ab(ll x){
	if (x>0) return x;
	return -x;
}

bool check(ll val){
	int i=0, j=0;
	for (; j<m; j++){
		while (i<n && ab(A[i]-B[j])<=val) i++;
	}
	return i==n;
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<n; i++) cin>>A[i];
	for (int i=0; i<m; i++) cin>>B[i];
	
	ll l=0, r= (ll) 2000 * 1000 * 1000 + 10;
	
	while (r-l>2){
		ll mid=(l+r)/2;
		if (check(mid)) r=mid+1;
		else l=mid+1;
	}
	if (check(l)){
		cout<<l<<endl;
		return 0;
	}
	cout<<l+1<<endl;
	
	return 0;
}