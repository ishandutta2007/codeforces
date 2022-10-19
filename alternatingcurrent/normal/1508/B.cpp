#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n;
ll k;
ll pow2;
vector<int> ans;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		ans.clear();
		cin >> n >> k;
		k--;
		pow2 = 1LL;
		rep(i, n - 1) if(pow2 < 1e18) pow2 = pow2 * 2LL;
		if(k >= pow2) cout << "-1" << endl;
		else {
			ll pos = 0;
			int lstpos = n;
			for(pos = 0; pos <= min(n - 1, 62); pos++){
				if(!(k & (1ll << pos))){
					int nxtpos = n - pos - 1;
//					cout << nxtpos << " to " << lstpos << endl;
					for(int i = nxtpos + 1; i <= lstpos; i++) ans.push_back(i);
					lstpos = nxtpos;
				}
			}
			for(int i = 1; i <= lstpos; i++) cout << i << " ";
			for(int i = (int)ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
			cout << endl;
		}
	}
	return 0;
}