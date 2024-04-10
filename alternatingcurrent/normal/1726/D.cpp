#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, m;
int from[400400], to[400400];
vector<int> v[200200];
int pare[200200];
bool done[200200], doing[200200];
int dept[200200];

vector<int> cy;
void dfs(int now){
//	cout << now << endl;
	doing[now] = done[now] = 1;
	rep(i, (int)v[now].size()){
		if(doing[to[v[now][i]]] && v[now][i] != pare[now]){
//			cout << now << " "  << to[v[now][i]] << " " << done[to[v[now][i]]] << " cyucycyc" << endl;
			cy.push_back(v[now][i]);
		} else {
			if(!done[to[v[now][i]]]){
				dept[to[v[now][i]]] = dept[now] + 1;
//				cout << now << " to " << to[v[now][i]] << endl;
				pare[to[v[now][i]]] = v[now][i] ^ 1;
				dfs(to[v[now][i]]);
			}
		}
	}
	doing[now] = 0;
}

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, n)
			v[i].clear();
		rep(i, m){
			int a, b;
			cin >> a >> b;
			a--, b--;
			from[i + i] = a, to[i + i] = b; v[a].push_back(i + i);
			from[i + i + 1] = b, to[i + i + 1] = a; v[b].push_back(i + i + 1);
		}
		memset(done, 0, sizeof(done));
		pare[0] = -1;
		cy.clear();
		dfs(0);
		assert((int)cy.size() == m - n + 1);
		if((int)cy.size() == 3){
			set<int> p;
			rep(i, (int)cy.size()) p.insert(from[cy[i]]), p.insert(to[cy[i]]);
			if((int)p.size() == 3){
//				cout << "fuck" << endl;
				int f = from[cy.back()]; cy.pop_back();
				cy.push_back(pare[f]);
			}
		}
		vector<bool> ans(m, 0);
//		cout << (int)cy.size() << endl;
		rep(i, (int)cy.size()){
//			cout << cy[i] << " " << from[cy[i]] << " " << to[cy[i]] << endl;
			ans[cy[i] / 2] = 1;
		}
		rep(i, m)
			cout << ans[i];
		cout << "\n";
	}
	return 0;
}