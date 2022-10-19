#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int a[100100];
void solve(){
	cin >> n;
	
	rep(i, n)
		cin >> a[i];
	
	int ans = 0;
	for(int l = 0, r = n-1; l < r; ){
		while(l < r && a[l] == 0)
			++l;
		while(l < r && a[r] == 1)
			--r;
		if(l >= r)
			break;
		++ans;
		swap(a[l], a[r]);
	}
	cout << ans << "\n";
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}