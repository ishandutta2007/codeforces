#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, x1, x2;
	cin >> n >> x1 >> x2;

	vector<pii> c(n);
	trav(x, c) cin >> x.first;
	rep(i,0,n) c[i].second = i+1;
	sort(all(c));
	reverse(all(c));

	swap(x1, x2);
	rep(t, 0, 2){
		swap(x1,x2);	
		
		int k1 = -1;

		rep(i,1,n){
			if( ll(c[i-1].first)*i >= x1){
				k1 = i;
				break;
			}
		}
		if(k1==-1) continue;

		int k2 = -1;
		rep(i,1,n-k1+1){
			if( ll(c[k1+i-1].first) * i >= x2){
				k2 = i;
				break;
			}
		}
		if(k2 == -1) continue;

		cout << "Yes" << endl;
		if(t==0) cout << k1 << ' ' << k2 << endl;
		else     cout << k2 << ' ' << k1 << endl;

		if(t==0){
			rep(i,0,k1) cout << c[i].second << ' ';
			cout << endl;
			rep(i,k1,k1+k2) cout << c[i].second << ' ';
			cout << endl;
		} else {
			rep(i,k1,k1+k2) cout << c[i].second << ' ';
			cout << endl;
			rep(i,0,k1) cout << c[i].second << ' ';
			cout << endl;
		}
		return 0;
	}

	cout << "No" << endl;
}