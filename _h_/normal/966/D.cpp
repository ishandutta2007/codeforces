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

void skriv(vi ans){
	cout << sz(ans)-1 << endl;
	trav(x,ans) cout << x+1 << ' ';
	cout << endl;
	exit(0);
}

int main(){
	int n, m;
	cin >> n >> m;

	vector<vi> gr(n);

	rep(_,0,m){
		int u, v;
		cin >> u >> v;
		--u, --v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}

	vector<int> pek(n, -1);
	pek[0] = -2;

	queue<int> ko;
	ko.push(0);

	while(!ko.empty()){
		int v = ko.front();
		ko.pop();

		trav(u, gr[v]){
			if(pek[u] == -1){
				pek[u] = v;
				ko.push(u);
			}
		}
	}
	vi cand;
	if(pek[n-1] != -1){
		int v = n-1;
		do {
			cand.push_back(v);
			v = pek[v];
		} while(v != 0);
		cand.push_back(0);
		reverse(all(cand));
	}

	vector<bool> close(n, false);
	trav(u, gr[0]) close[u] = true;
	close[0] = true;
	
	vi cand2;

	trav(u, gr[0]) trav(v, gr[u]){
		if(!close[v]){
			cand2.push_back(0);
			cand2.push_back(u);
			cand2.push_back(v);
			cand2.push_back(0);
			cand2.push_back(n-1);
			goto good;
		}
	}
	good: ;
	
	close[0] = false;

	vi cand3;

	vector<bool> vis(n, false);

	vector<vi> gr2(n);
	rep(i,0,n) if(close[i]) trav(j, gr[i]) if(close[j]) gr2[i].push_back(j);

	rep(i,0,n) if(close[i] && !vis[i]){
		
		trav(j, gr2[i]) vis[j] = true;
		vis[i] = true;

		trav(j, gr2[i]){
			if(sz(gr2[j]) < sz(gr2[i])){
				rep(x,0,n) vis[x] = false;
				trav(x, gr2[j]) vis[x] = true;
				vis[j] = true;
				trav(y, gr2[i]) if(!vis[y]){
					cand3.push_back(0);
					cand3.push_back(j);
					cand3.push_back(i);
					cand3.push_back(y);
					cand3.push_back(j);
					cand3.push_back(n-1);
					goto good2;
				}

			}
			trav(y, gr2[j]) if(!vis[y]){
				cand3.push_back(0);
				cand3.push_back(i);
				cand3.push_back(j);
				cand3.push_back(y);
				cand3.push_back(i);
				cand3.push_back(n-1);
				goto good2;
			}
				
		}
	}
	good2: ;
	
	if(cand.empty() && cand2.empty() && cand3.empty()){
		cout << -1 << endl;
		return 0;
	}
	if(!cand2.empty()){
		if(cand.empty() || sz(cand) > sz(cand2)){
			skriv(cand2);
		} else
			skriv(cand);
	}
	if(!cand3.empty()){
		if(cand.empty() || sz(cand) > sz(cand3))
			skriv(cand3);
		else
			skriv(cand);
	}
	skriv(cand);
}