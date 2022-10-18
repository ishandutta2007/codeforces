#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

struct no{
	vector<int> ch;
	int fa=0;
};

vector<no> v;
vector<int> d;
void dfs(int r,int f){
	d.push_back(r);
	v[r].fa=f;
	for(int i=0;i<v[r].ch.size();i++){
		if(v[r].ch[i]==v[r].fa){
			continue;
		}
		dfs(v[r].ch[i],r);
	}
}


int main(){
	//fastio;
	int n;
	cin >> n;
	v.resize(n+1);
	int a,b;
	for(int i=1;i<n;i++){
		cin >> a >> b;
		v[a].ch.push_back(b);
		v[b].ch.push_back(a);
	}
	//d.push_back(0);
	dfs(1,0);
	
	cout << "? " << n;
	for(int i=1;i<=n;i++){
		cout << " " << i;
	}
	cout << endl;
	int mx;
	cin >> mx;
	int l=1,r=n;
	while(1){
		if(r-l<=1){
			break;
		}
		int m=(l+r)/2;
		vector<int> y(n+1);
		for(int i=l;i<m;i++){
			y[d[i]]=1;
			y[v[d[i]].fa]=1;
		}
		int c=0;
		vector<int> po;
		for(int i=1;i<=n;i++){
			if(y[i]==1){
				c++;
				po.push_back(i);
			}
		}
		cout << "? " << c;
		for(int i=0;i<c;i++){
			cout << " " << po[i];
		}
		cout << endl;
		int u;
		cin >> u;
		if(u==mx){
			r=m;
		}
		else{
			l=m;
		}
	}
	cout << "! " << d[l] << " " << v[d[l]].fa << endl;
		
	return 0;
}