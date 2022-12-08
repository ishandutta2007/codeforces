#include <bits/stdc++.h>

using namespace std;

int myrand(int p) {
	return 1LL * rand() * rand() % p; 
}

vector<int> solve(int u,int p) {
	while(1) {
		int k=myrand(p);
		if (k==0) continue;
		int a=1LL*u*k%p,b=k;
		vector<int>ret;
		while(a){
			if(a>=b) {
				a-=b;
				ret.push_back(0);
			}
			else{
				swap(a,b);
				ret.push_back(1);
			}
			if (ret.size() > 100) break;
		}
		if (ret.size() <= 100) return ret;
	}
}
int main() {
	int u, v, p; 
	cin>>u>>v>>p;
	vector<int> f = solve(u, p);
	vector<int> g = solve(v, p);
	reverse(g.begin(), g.end());
	cout <<f.size()+g.size()<<'\n';
	for (int i=0;i<f.size();i++)
	     cout<<(f[i]?3:2)<<' ';
	for (int i=0;i<g.size();i++)
	     cout<<(g[i]?3:1)<<' ';
}