#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e5+7;
vector<int>V[LIM];
int T[LIM][3], ile[LIM], pi[LIM], odw[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i, n-2) rep(j, 3) {
		cin >> T[i][j]; --T[i][j];
		++ile[T[i][j]];
		V[T[i][j]].pb(i);
	}
	priority_queue<pair<int,int>>q;
	rep(i, n) if(ile[i]==1) {
		q.push({1, i});
		odw[i]=1;
		break;
	}
	rep(i, n) pi[i]=ile[i];
	rep(i, n) {
		int p=q.top().nd; q.pop();
		cout << p+1 << " ";
		for(auto j : V[p]) rep(l, 3) {
			--ile[T[j][l]];
			if(ile[T[j][l]]<=1 && !odw[T[j][l]]) {
				odw[T[j][l]]=1;
				q.push({pi[T[j][l]], T[j][l]});
			}
		}
	}
	cout << '\n';
}