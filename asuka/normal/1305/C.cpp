#include<bits/stdc++.h>
#define int long long
#define N 200015
#define M 1015
using namespace std;
int n,m,a[N],tot[M];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
		tot[a[i]%m]++;
	}
	for(int i = 0;i < m;++i){
		if(tot[i] > 1){
			cout << 0 << endl;
			return 0;
		}
	}
	int res = 1;
	for(int i = 1;i <= n;++i){
		for(int j = i+1;j <= n;++j){
			res = (res%m*abs(a[i]-a[j])%m)%m; 
		}
	}
	cout << res%m << endl;
	return 0;
}