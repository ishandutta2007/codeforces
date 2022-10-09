#include <bits/stdc++.h>
using namespace std;

int n;
bool blocked[44][722];

int dr[4]={-1,1,0,0};
int dt[4]={0,0,-1,1};

inline bool isok(int r, int t){
	if(r<0||blocked[r][t]) return 0;
	return 1;
}

void solve(){
	memset(blocked, 0, sizeof(blocked));
	cin>>n;
	for(int i=1;i<=n;++i){
		char tip;
		cin>>tip;
		if(tip=='C'){
			int r, t1, t2;
			cin>>r>>t1>>t2;
			t1*=2;
			t2*=2;
			r*=2;
			if(t1>t2){
				for(int i=0;i<t2;++i) blocked[r][i]=1;
				for(int i=t1;i<720;++i) blocked[r][i]=1;
			}
			else{
				for(int i=t1;i<=t2;++i) blocked[r][i]=1;
			}
		}
		else{
			int r1, r2, t;
			cin>>r1>>r2>>t;
			r1*=2, r2*=2;
			t*=2;
			for(int i=r1;i<=r2;++i) blocked[i][t]=1;
		}
	}
	queue<pair<int, int>> q;
	q.push({0, 0});
	blocked[0][0]=1;
	while(!q.empty()){
		int r, t;
		tie(r, t)=q.front();
		q.pop();
		for(int k=0;k<4;++k){
			int nr=r+dr[k], nt=t+dt[k];
			if(nt<0) nt=720+nt;
			if(nt>=720) nt=nt-720;
			if(!isok(nr, nt)) continue;
			if(nr>41){
				cout<<"YES\n";
				return;
			}
			q.push({nr, nt});
			blocked[nr][nt]=1;
		}
	}
	cout<<"NO\n";
}

int main(){
	int t;
	cin>>t;
	while(t--) solve();
}