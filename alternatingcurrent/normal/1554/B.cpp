#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n, k;
int a[100100];
ll mxind[2][200200];
// 2^17 = 131072

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> k;
		rep(i, n)
			cin >> a[i];
		int mxbit = 17;
		while(!((n >> mxbit) & 1))
			mxbit--;
		rep(i, 1 << (mxbit + 1))
			mxind[0][i] = mxind[1][i] = 0xc0c0c0c0c0c0c0c0;
		rep(i, n){
			if(i > mxind[0][a[i]])
				mxind[1][a[i]] = mxind[0][a[i]], mxind[0][a[i]] = i;
			else if(i > mxind[1][a[i]])
				mxind[1][a[i]] = i;
		}
		rep(bit, mxbit + 1){
			rep(i, 1 << (mxbit + 1)){
				if(!((i >> bit) & 1)){
					vector<int> mx;
					mx.push_back(mxind[0][i | (1 << bit)]);
					mx.push_back(mxind[1][i | (1 << bit)]);
					mx.push_back(mxind[0][i]);
					mx.push_back(mxind[1][i]);
					sort(mx.begin(), mx.end());
					mxind[0][i | (1 << bit)] = mx[3], mxind[1][i | (1 << bit)] = mx[2];
				}
			}
		}
		ll ans = 0xc0c0c0c0c0c0c0c0;
		rep(i, 1 << (mxbit + 1)){
			if(mxind[1][i] >= 0){
				ans = max(ans, (mxind[0][i] + 1) * (mxind[1][i] + 1) - 1LL * k * i);
			}
		}
		cout << ans << endl;
	}
	return 0;
}