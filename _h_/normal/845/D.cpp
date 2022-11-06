#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int ans = 0, noot = 0;
	vi lims(1, 500);
	int myspeed = -1;
	rep(_,0,n){
		int t, speed;
		cin >> t;
		if(t == 1 || t == 3) cin >> speed;
		if(t == 1){
			myspeed = speed;
			while(lims.back() < speed){
				++ans;
				lims.pop_back();
			}
		} else if(t == 2){
			ans += noot;
			noot = 0;
		} else if(t == 3){
			if(speed < myspeed) ++ans;
			else lims.push_back(speed);
		} else if(t == 4){
			noot = 0;
		} else if(t == 5){
			lims.push_back(500);
		} else if(t == 6){
			++noot;
		}
	}
	cout << ans << endl;
}