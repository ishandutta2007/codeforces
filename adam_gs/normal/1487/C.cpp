#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e5+7, MOD=1e9+7;
void solve() {
	int n;
	cin >> n;
	int wyg[n], rem[n];
	rep(i, n) {wyg[i]=0;rem[i]=0;}
	if(n%2==1) {
		rep(i, n) {
			for(int j=i+1; j<n; ++j) {
				if(wyg[i]<n/2) {
					cout << "1 ";
					++wyg[i];
				} else {
					cout << "-1 ";
					++wyg[j];
				}
			}
		}
	} else {
		rep(i, n) {
			for(int j=i+1; j<n; ++j) {
				if(!rem[i]) {
					rem[i]=1;
					rem[j]=1;
					cout << "0 ";
				} else if((j+i)%2) {
					cout << "1 ";
					++wyg[i];
				} else {
					cout << "-1 ";
					++wyg[j];
				}
			}
		}
	}
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	//t=1;
	while(t--) solve();
}