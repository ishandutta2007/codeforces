#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

struct no{
	vector<int> ch;
	vector<pair<int,int> > qu;
	int dep=-1;
	int fa=-1;
	int mxdep=0,mxch=-1;
};
vector<int> ans;
vector<no> v;
void dfs(int r,int f){
	v[r].dep=v[f].dep+1;
	v[r].mxdep=v[r].dep;
	for(auto h:v[r].ch){
		dfs(h,r);
		if(v[h].mxdep>v[r].mxdep){
			v[r].mxdep=v[h].mxdep;
			v[r].mxch=h;
		}
	}
}
void dfs2(int r,int t,vector<int>& x){
	if(v[r].mxch==-1){
		if(t==0){
			x.push_back(1);
		}
		else{
			x[x.size()-1]++;
		}
		return;
	}
	if(t==0){
		dfs2(v[r].mxch,0,x);
		for(auto h:v[r].ch){
			if(h!=v[r].mxch){
				dfs2(h,1,x);
			}
		}
		int f=x.size();
		for(auto h:v[r].qu){
			ans[h.fs]=x[f-h.sc]-1;
		}
		x.push_back(1);
	}
	else{
		vector<int> y;
		dfs2(v[r].mxch,0,y);
		for(auto h:v[r].ch){
			if(h!=v[r].mxch){
				dfs2(h,1,y);
			}
		}
		int f=x.size(),g=y.size();
		for(auto h:v[r].qu){
			ans[h.fs]=y[g-h.sc]-1;
		}
		y.push_back(1);
		g++;
		if(f<g){
			cout << r+1 << " " << f << " " << g << "\n";
			cout << v[v[r].fa].mxdep-v[v[r].fa].dep << " " << v[r].mxdep-v[r].dep << "\n";
			exit(0);
		}
		for(int i=1;i<=g;i++){
			x[f-i]+=y[g-i];
		}
		//x.push_back(1);
	}
}
int main(){
	AquA;
	int n;
	cin >> n;
	v.resize(n);
	vector<array<int,20> > as(n);
	for(int i=0;i<n;i++){
		cin >> v[i].fa;
		v[i].fa--;
		as[i][0]=v[i].fa;
		if(v[i].fa>=0){
			v[v[i].fa].ch.push_back(i);
		}
	}
	for(int i=0;i<n;i++){
		if(v[i].fa==-1){
			dfs(i,i);
		}
	}
	for(int i=1;i<18;i++){
		for(int j=0;j<n;j++){
			if(as[j][i-1]>=0){
				as[j][i]=as[as[j][i-1]][i-1];
			}
			else{
				as[j][i]=-1;
			}
		}
	}
	int q;
	cin >> q;
	ans.resize(q);
	for(int i=0;i<q;i++){
		int a,b;
		cin >> a >> b;
		a--;
		int c=a,d=b;
		if(v[a].dep<b){
			ans[i]=0;
			continue;
		}
		int y=0;
		while(b){
			if(b&1){
				c=as[c][y];
			}
			b>>=1;
			y++;
		}
		v[c].qu.push_back(pair<int,int>(i,d));
	}
	for(int i=0;i<n;i++){
		if(v[i].fa==-1){
			vector<int> tmp;
			dfs2(i,0,tmp);
		}
	}
	for(int i=0;i<q;i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}