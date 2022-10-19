#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
const int LIM=5e5+7, MOD=1e9+7;
int odw[LIM], ile;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	queue<int>kol;
	priority_queue<pair<int,int>>pr;
	while(q--) {
		int x;
		cin >> x;
		if(x==1) {
			int m;
			cin >> m;
			kol.push(ile);
			pr.push({m, -ile});
			++ile;
		} else if(x==2) {
			while(odw[kol.front()]) kol.pop();
			cout << kol.front()+1 << " ";
			odw[kol.front()]=1;
			kol.pop();
		} else {
			while(odw[-pr.top().nd]) pr.pop();
			cout << -pr.top().nd+1 << " ";
			odw[-pr.top().nd]=1;
			pr.pop();
		}
	}
}