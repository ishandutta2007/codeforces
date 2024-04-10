#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e3+7;
int T[LIM];
int main() {
	int n;
	cin >> n;
	T[1]=1;
	rep(i, n-2) {
		cout << 2 << " " << T[0]+1 << " " << T[1]+1 << " " << i+3 << endl;
		int x;
		cin >> x;
		if(x==-1) T[1]=i+2;
	}
	vector<pair<ll,int>>V;
	rep(i, n-1) if(i+1!=T[1]) {
		cout << 1 << " " << T[0]+1 << " " << T[1]+1 << " " << i+2 << endl;
		ll x;
		cin >> x;
		V.pb({x, i+1});
	}
	sort(all(V));
	vector<int>A, B;
	rep(i, V.size()-1) {
		cout << 2 << " " << T[0]+1 << " " << V[i].nd+1 << " " << V[i+1].nd+1 << endl;
		int x;
		cin >> x;
		if(x==1) A.pb(V[i].nd);
		else B.pb(V[i].nd);
	}
	A.pb(V.back().nd);
	reverse(all(B));
	for(auto i : B) A.pb(i);
	cout << 0 << " " << T[0]+1 << " " << T[1]+1 << " ";
	for(auto i : A) cout << i+1 << " ";
	cout << endl;
}