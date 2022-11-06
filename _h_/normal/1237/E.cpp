// written by aitch
// on 2019 10/16 at 15:35:00
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef char ll;
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int a = 1, b = 2;

	bool foo = true;

	while(min(a,b) <= n){
		if(a == n || b == n){
			cout << 1 << endl;
			return 0;
		}
		if(foo){
			a = b*2;
			b = b*2+1;
		} else {
			a = b*2-1;
			b = b*2;
		}
		foo = !foo;
	}
	cout << 0 << endl;
}