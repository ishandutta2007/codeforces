#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=1010;

int n, x, xx, cur=1, ans=1;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>x;
	for (int i=1; i<n; i++){
		cin>>xx;
		if (xx>x) ans=max(ans, ++cur);
		
		else cur=1;
		x=xx;
	}
	cout<<ans<<endl;
		
	return 0;
}