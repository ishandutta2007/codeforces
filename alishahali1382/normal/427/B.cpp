#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int MAXN=200 * 1000 + 10;

int n, t, c, l, ans;
int A[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>t>>c;
	for (int i=1; i<=n; i++){
		cin>>A[i];
	}
	A[n+1]=t+1;
	
	for (int i=1; i<=n+1; i++){
		if (A[i]<=t) continue ;
		ans+=max(i-l-c, 0);
		l=i;
	}
	
	cout<<ans<<endl;
	
	return 0;
}