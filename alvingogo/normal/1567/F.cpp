#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int dx[8]={0,1,0,-1,1,1,-1,-1},dy[8]={1,0,-1,0,1,-1,1,-1};
int main(){
	AquA;
	int n,m;
	cin >> n >> m;
	auto in=[&](int x,int y){
		return x>=0 && x<n && y>=0 && y<m;
	};
	vector<string> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(v[i][j]=='X'){
				int dg=0;
				for(int k=0;k<4;k++){
					if(in(i+dx[k],j+dy[k]) && v[i+dx[k]][j+dy[k]]=='.'){
						dg++;
					}
				}
				if(dg%2){
					cout << "NO\n";
					return 0;
				}
			}
		}
	}
	vector<vector<int> > cc(n,vector<int>(m));
	int cnt=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(v[i][j]=='.' && !cc[i][j]){
				queue<pair<int,int> > q;
				q.push({i,j});
				cc[i][j]=cnt;
				while(q.size()){
					auto h=q.front();
					q.pop();
					for(int k=0;k<8;k++){
						int ni=h.fs+dx[k],nj=h.sc+dy[k];
						if(in(ni,nj)){
							if(v[ni][nj]=='.' && !cc[ni][nj]){
								cc[ni][nj]=cnt;
								q.push({ni,nj});
							}
						}
					}
				}
				cnt++;
			}
		}
	}
	vector<vector<int> > e(cnt,vector<int>(cnt));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(v[i][j]=='X'){
				for(int k=0;k<2;k++){
					int ax=i+dx[k],ay=j+dy[k];
					int bx=i+dx[k+2],by=j+dy[k+2];
					if(in(ax,ay) && in(bx,by) && v[ax][ay]=='.' && v[bx][by]=='.'){
						if(cc[ax][ay]!=cc[bx][by]){
							e[cc[ax][ay]][cc[bx][by]]=e[cc[bx][by]][cc[ax][ay]]=1;
						}
					}
				}
			}
		}
	}
	vector<int> co(cnt);
	for(int i=1;i<cnt;i++){
		if(!co[i]){
			co[i]=1;
			queue<int> q;
			q.push(i);
			while(q.size()){
				auto h=q.front();
				q.pop();
				for(int j=1;j<cnt;j++){
					if(e[h][j] && !co[j]){
						co[j]=-co[h];
						q.push(j);
					}
				}
			}
		}
	}
	vector<vector<int> > ans(n,vector<int>(m));
	for(int i=0;i<n;i++){
		int now=0;
		for(int j=0;j<m;j++){
			if(v[i][j]=='.'){
				ans[i][j]=(co[cc[i][j]]+5)%5;
				if(i%2==0){
					ans[i][j]=5-ans[i][j];
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(v[i][j]=='X'){
				for(int k=0;k<4;k++){
					if(in(i+dx[k],j+dy[k]) && v[i+dx[k]][j+dy[k]]=='.'){
						ans[i][j]+=ans[i+dx[k]][j+dy[k]];
					}
				}
			}
		}
	}
	cout << "YES\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}