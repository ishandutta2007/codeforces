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

	int n;
	cin >> n;

	int rek = 2e9, ans = -1;

	rep(i,0,n){
		int a;
		cin >> a;

		int cur = 0;
		cur += i;
		a = max(0, a-i);

		a += n-1;
		a -= a%n;
		cur += a;

		if(rek > cur){
			rek = cur;
			ans = i;
		}
	}

	cout << ans+1 << endl;
}