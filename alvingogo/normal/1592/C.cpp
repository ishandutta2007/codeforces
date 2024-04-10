#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

struct no{
	int xp=0;
	int sxp=0;
	bool f1=0;
	bool f2=0;
	vector<int> ch;
	int fa=0;
};
vector<no> v;
int nx=0;
void dfs(int r,int f){
	v[r].fa=f;
	int l=v[r].ch.size();
	int y=0;
	for(int i=0;i<l;i++){
		if(v[r].ch[i]==f){
			continue;
		}
		dfs(v[r].ch[i],r);
		v[r].sxp^=v[v[r].ch[i]].sxp;
		if(v[v[r].ch[i]].f2==1){
			v[r].f2=1;
		}
		if(v[v[r].ch[i]].f1==1){
			y++;
		}
	}
	if(y>=1 || v[r].sxp==nx){
		v[r].f1=1;
	}
	if(y>1 || (y==1 && v[r].sxp==0)){
		v[r].f2=1;
	}
}
int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		nx=0;
		v.clear();
		v.resize(n+1);
		int a,b;
		for(int i=1;i<=n;i++){
			cin >> v[i].xp;
			v[i].sxp=v[i].xp;
			nx^=v[i].xp;
		}
		for(int i=1;i<n;i++){
			cin >> a >> b;
			v[a].ch.push_back(b);
			v[b].ch.push_back(a);
		}
		if(nx==0){
			cout << "YES\n";
			continue;
		}
		if(k==2){
			cout << "NO\n";
			continue;
		}
		dfs(1,0);
		if(v[1].f2==0){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
	
	
	return 0;
}