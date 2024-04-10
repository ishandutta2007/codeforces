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

	if(n <= 3){
		cout << 0 << endl;
		return 0;
	}

	int a = 1, b = 1;
	while(a * b < n){
		a++;
		if(a > b) swap(a,b);
	}

	vector<bool> cur(n, false);

	stack<int> wnt;

	rep(i,0,n) if(i % b != 0) wnt.push(i);

	while(sz(wnt) >= b){
		cout << b;
		rep(_,0,b){
			int y = wnt.top();
			cout << " " << y+1;
			cur[y] = true;
			wnt.pop();
		}
		cout << endl;

		int x;
		cin >> x;
		
		rep(t,0,b){
			int y = (x-1 + t) % n;
			if(cur[y]){
				cur[y] = false;
				wnt.push(y);
			}
		}
	}

	cout << 0 << endl;
}