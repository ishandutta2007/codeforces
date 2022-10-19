#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
vector<int>V[LIM];
int lst[LIM], kto[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, s;
	cin >> n >> m >> s; --s;
	rep(i, n) lst[i]=kto[i]=-1;
	while(m--) {
		int a, b;
		cin >> a >> b; --a; --b;
		if(b!=s) V[a].pb(b);
	}
	queue<pair<int,int>>q;
	lst[s]=s;
	for(auto i : V[s]) {
		lst[i]=s;
		kto[i]=i;
		q.push({i, i});
	}
	while(!q.empty()) {
		int a=q.front().st, b=q.front().nd; q.pop();
		for(auto i : V[a]) {
			if(kto[i]==-1) {
				kto[i]=b;
				lst[i]=a;
				q.push({i, b});
			} else if(kto[i]!=b) {
				vector<int>A, B;
				int x=a;
				A.pb(i);
				while(x!=s) {
					A.pb(x);
					x=lst[x];
				}
				A.pb(s);
				x=i;
				while(x!=s) {
					B.pb(x);
					x=lst[x];
				}
				B.pb(s);
				reverse(all(A));
				reverse(all(B));
				cout << "Possible\n" << A.size() << '\n';
				for(auto i : A) cout << i+1 << " ";
				cout << '\n' << B.size() << '\n';
				for(auto i : B) cout << i+1 << " ";
				cout << '\n';
				return 0;
			}
		}
	}
	cout << "Impossible\n";
}