#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=210; typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
int n,m;
bool a[N][N];
vector<int> p[N];
int c[N];
vector<int> rec;
vector<vector<int>> ans;
void remove(int x,int y){
	a[x][y]=0;
	c[y]--;
}
void resume(int x,int y){
	a[x][y]=1;
	c[y]++;
}
void work(int x,int y,int dep){
	if(!a[x][y])return;
	if(c[y]!=1)return;
	if(dep==n){
		if(p[x].size()!=2)return;
		rec.push_back(p[x][0]);
		rec.push_back(p[x][1]);
		ans.push_back(rec);
		reverse(ans.back().begin(),ans.back().end());
		rec.pop_back();
		rec.pop_back();
		rec.push_back(p[x][1]);
		rec.push_back(p[x][0]);
		ans.push_back(rec);
		reverse(ans.back().begin(),ans.back().end());
		rec.pop_back();
		rec.pop_back();
		return;
	}
	rec.push_back(y);
	for(auto j:p[x])
		remove(x,j);
	for(auto j:p[x])
	repeat(i,0,n){
		work(i,j,dep+1);
	}
	for(auto j:p[x])
		resume(x,j);
	rec.pop_back();
	return;
}
void output(const vector<int> &ans){
	for(auto i:ans)
		cout<<i+1<<' ';
	cout<<endl;
}
bool ok(const vector<int> &ans){
	static int pos[N];
	static vector<int> a;
	repeat(i,0,ans.size())
		pos[ans[i]]=i;
	repeat(x,0,n){
		a.clear();
		for(auto y:p[x]){
			a.push_back(pos[y]);
		}
		sort(a.begin(),a.end());
		repeat(i,0,a.size()-1)
		if(a[i]!=a[i+1]-1)
			return 0;
	}
	return 1;
}
void work0(){
	repeat(i,0,n)
	repeat(j,0,m)
		work(i,j,1);
	for(auto &i:ans)
	if(ok(i)){
		output(i);
		return;
	}
}
signed main(){
	for(int T=read();T--;){
		n=read()-1; m=n+1;
		repeat(i,0,m)
		repeat(j,0,m)
			a[i][j]=0;
		repeat(i,0,m)c[i]=0;
		repeat(i,0,m)p[i].clear();
		ans.clear();
		
		repeat(x,0,n){
			int t=read();
			while(t--){
				int y=read()-1;
				a[x][y]=1;
				c[y]++;
				p[x].push_back(y);
			}
		}
		work0();
	}
	return 0;
}