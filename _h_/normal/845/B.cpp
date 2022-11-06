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
	
	string s;
	cin >> s;
	vi a(6);
	rep(i,0,6) a[i] = s[i]-'0';
	int dif = 0;
	rep(i,0,3) dif += a[i]-a[i+3];
	if(dif < 0){
		dif = -dif;
		rep(i,0,3) swap(a[i], a[i+3]);
	}
	vi moves(6);
	rep(i,0,3){
		moves[i] = a[i]-0;
		moves[i+3] = 9-a[i+3];
	}
	sort(all(moves)); reverse(all(moves));
	rep(i,0,6){
		if(dif <= 0){
			cout << i << endl;
			return 0;
		}
		dif -= moves[i];
	}
}