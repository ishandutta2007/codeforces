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
	vector<vi> children(n);
	rep(i,1,n){
		int p;
		cin >> p;
		children[p-1].push_back(i);
	}
	rep(i,0,n) if(!children[i].empty()){
		int cnt = 0;
		trav(x, children[i]) cnt += children[x].empty();
		if(cnt < 3){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}