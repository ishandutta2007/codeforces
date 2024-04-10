#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;

struct no{
	vector<int> ch;
	int s,c;
	int mx=0;
};
vector<no> v;
int ans=0;
void dfs(int r){
	int sz=v[r].ch.size();
	if(sz==0){
		v[r].mx=v[r].s;
		return;
	}
	vector<int> z;
	for(auto h:v[r].ch){
		v[h].c=v[r].c/sz;
		ans+=v[h].c*v[h].s;
		dfs(h);
		z.push_back(v[h].mx);
		v[r].mx=max(v[r].mx,v[h].mx);
	}	
	sort(z.begin(),z.end());
	for(int i=0;i<v[r].c%sz;i++){
		ans+=z.back();
		z.pop_back();
	}
	v[r].mx=z.back();
	v[r].mx+=v[r].s;
}
signed main(){
    AquA;
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		ans=0;
		v.clear();
		v.resize(n);
		for(int i=1;i<n;i++){
			int a;
			cin >> a;
			a--;
			v[a].ch.push_back(i);
		}
		for(int i=0;i<n;i++){
			cin >> v[i].s;
		}
		v[0].c=k;
		ans+=v[0].c*v[0].s;
		dfs(0);
		cout << ans << "\n";
	}	
    return 0;
}