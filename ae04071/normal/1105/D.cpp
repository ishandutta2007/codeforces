#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;
using lli = long long;

int n,m,p,s[10];
char str[1001][1001];
queue<pii> rem[10];
int dy[]={-1,1,0,0},dx[]={0,0,-1,1};

bool go(int y,int x) {
	return y>=0 && x>=0 && y<n && x<m &&  str[y][x]=='.';
}
int main() {
	scanf("%d%d%d",&n,&m,&p);
	for(int i=0;i<p;i++) scanf("%d",s+i);
	for(int i=0;i<n;i++) scanf("%s",str[i]);
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(isdigit(str[i][j])) str[i][j]-='0'+1;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(str[i][j]>=0 && str[i][j]<p){
		rem[str[i][j]].push(pii(i,j));
	}

	int c=0;
	for(int t=0;c<p;t=(t+1)%p) {
		queue<pii> que;
		while(!rem[t].empty()) {
			que.push(rem[t].front());
			rem[t].pop();
		}
		for(int tt=0;tt<s[t] && !que.empty();tt++) {
			int sz=que.size();
			while(sz--) {
				int y=que.front().fi ,x=que.front().se;
				que.pop();
				for(int k=0;k<4;k++) {
					int yy=y+dy[k],xx=x+dx[k];
					if(go(yy,xx)) {
						que.push(pii(yy,xx));
						str[yy][xx]=t;
					}
				}
			}
		}
		if(que.empty()) c++;
		else c=0;
		while(!que.empty()) {
			rem[t].push(que.front());
			que.pop();
		}
	}

	for(int t=0;t<p;t++) {
		int cnt=0;
		for(int i=0;i<n;i++) for(int j=0;j<m;j++)if(str[i][j]==t) cnt++;
		printf("%d ",cnt);
	}
	
	
	return 0;
}