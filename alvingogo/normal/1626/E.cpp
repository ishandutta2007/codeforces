#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

vector<vector<int> > e;

vector<int> bo;
int z=0;
vector<int> v;
void dfs(int r){
	bo[r]=z;
	for(auto h:e[r]){
		if(bo[h]==-1){
			dfs(h);
		}
	}
}

int main(){
	AquA;
	int n;
	cin >> n;
	v.resize(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	e.resize(n);
	for(int i=1;i<n;i++){
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	vector<int> ans(n);
	bo.resize(n,-1);
	int p=0;
	for(int i=0;i<n;i++){
		if(v[i]==1){
			for(auto h:e[i]){
				if(v[h]==0){
					ans[h]=1;
					bo[h]=z;
				}
			}
			ans[i]=1;
			bo[i]=z;
			z++;
			p++;
		}
	}
	for(int i=0;i<n;i++){
		if(v[i]==0){
			if(bo[i]==-1){
				dfs(i);
				z++;
			}
		}
	}
	vector<set<int> > f(n);
	for(int i=0;i<n;i++){
		for(auto h:e[i]){
			if(bo[i]!=bo[h]){
				f[bo[i]].insert(bo[h]);
			}
		}
	}
	vector<int> d(z);
	for(int i=0;i<z;i++){
		if(f[i].size()<p){
			d[i]=1;
		}
	}
	for(int i=0;i<n;i++){
		if(d[bo[i]]==1){
			ans[i]=1;
		}
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}