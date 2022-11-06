#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n){
		int junk;
		cin >> junk;
		string a, b;
		cin >> a >> b;
		vector<vector<bool>> vs(20, vector<bool>(20, false));
		bool foo = true;
		rep(i,0,sz(a)){
			if(a[i] > b[i]) foo = false;
			else if(a[i] < b[i])
				vs[a[i]-'a'][b[i]-'a'] = true;
		}
		if(!foo) cout << -1 << endl;
		else {
			int cnt = 0;
			rep(i,0,20){
				rep(j,i+1,20) if(vs[i][j]){
					rep(k,j+1,20) if(vs[i][k])
						vs[j][k] = true;
					++cnt;
					break;
				}
			}
			cout << cnt << endl;
		}
	}
}