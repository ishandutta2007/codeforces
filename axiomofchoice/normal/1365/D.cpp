#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=210; typedef long long ll;
//#define int ll
int n,m,T;
string s[N];
bool inside(int x,int y){
	return x>=0 && y>=0 && x<n && y<m;
}
bool good(int x,int y){
	return s[x][y]=='.' || s[x][y]=='G';
}
int dn[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
queue<pair<int,int>> q;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>m; repeat(i,0,n)cin>>s[i];
		int ans=true;
		repeat(x,0,n)
		repeat(y,0,m)
		if(s[x][y]=='B'){
			repeat(k,0,4){
				int px=x+dn[k][0];
				int py=y+dn[k][1];
				if(inside(px,py)){
					if(s[px][py]=='G')ans=false;
					if(s[px][py]=='.')s[px][py]='#';
				}
			}
		}
		if(s[n-1][m-1]=='B')ans=false;
		if(good(n-1,m-1)){
			s[n-1][m-1]='o';
			q.push({n-1,m-1});
			while(!q.empty()){
				int x=q.front().first,y=q.front().second;
				q.pop();
				repeat(k,0,4){
					int px=x+dn[k][0];
					int py=y+dn[k][1];
					if(inside(px,py) && good(px,py)){
						s[px][py]='o';
						q.push({px,py});
					}
				}
			}
		}
		repeat(i,0,n)
		repeat(j,0,m)
		if(s[i][j]=='G')
			ans=false;
		cout<<(ans?"Yes":"No")<<endl;
	}
	return 0;
}