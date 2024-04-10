#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
using namespace std;

struct no{
	int fa;
	vector<int> ch;
	int dep=-1;
};

vector<no> te;
void dfs(int r,int f){
	te[r].fa=f;
	te[r].dep=te[te[r].fa].dep+1;
	for(int i=0;i<te[r].ch.size();i++){
		if(te[r].ch[i]==f){
			continue;
		}
		
		dfs(te[r].ch[i],r);
	}
}
vector<int> vis;
vector<vector<int> > v;
void dt(int r){
	vis[r]=1;
	for(int i=0;i<v[r].size();i++){
		if(vis[v[r][i]]==0){
			te[r].ch.push_back(v[r][i]);
			te[v[r][i]].ch.push_back(r);
			dt(v[r][i]);
		}
	}
}
int main(){
	fastio;
	int n,k;
	cin >> n >> k;
	int a,b;
	te.resize(n+1);
	vis.resize(n+1);
	v.resize(n+1);
	for(int i=0;i<k;i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int q;
	cin >> q;
	vector<pair<int,int> > qe(q);
	vector<int> w(n+1);
	for(int i=0;i<q;i++){
		cin >> qe[i].fs >> qe[i].sc;
		w[qe[i].fs]++;
		w[qe[i].sc]++;
	}
	int h=0;
	for(int i=1;i<=n;i++){
		if(w[i]%2){
			h++;
		}
	}
	if(h!=0){
		cout << "NO\n";
		cout << h/2 << "\n";
	}
	else{
		cout << "YES\n";
		dt(1);
		dfs(1,0);
		for(int i=0;i<q;i++){
			int x=qe[i].fs;
			int y=qe[i].sc;
			vector<int> vx,vy;
			vx.push_back(x);
			vy.push_back(y);
			while(te[x].dep>te[y].dep){
				x=te[x].fa;
				vx.push_back(x);
			}
			while(te[y].dep>te[x].dep){
				y=te[y].fa;
				vy.push_back(y);
			}
			while(x!=y){
				x=te[x].fa;
				y=te[y].fa;
				vx.push_back(x);
				vy.push_back(y);
			}
			reverse(vy.begin(),vy.end());
			for(int i=1;i<vy.size();i++){
				vx.push_back(vy[i]);
			}
			cout << vx.size() << "\n";
			for(int i=0;i<vx.size();i++){
				cout << vx[i] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}