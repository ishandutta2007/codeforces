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
	int n;
	cin >> n;
	int s = 0, h = 0;
	rep(i,0,n){
		string u,t;
		cin >> u >> t;
		if(t == "soft") s++;
		else h++;
	}
	int ans = 1;
	do {
		int a = ans*ans / 2, b = ans*ans - a;
		if(max(a,b) >= max(s,h) && min(a,b) >= min(s,h)){
			cout << ans << endl;
			return 0;
		}
	} while(ans ++);
}