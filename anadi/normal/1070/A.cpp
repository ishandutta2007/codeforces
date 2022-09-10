#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 507;
const int M = 5007;

int d, s;
PII p[N][M];

int res[N][M];
queue <PII> Q;
bool vis[N][M];

int main(){
	scanf("%d %d", &d, &s);
	vis[0][0] = true;
	Q.push({0, 0});
	
	while(!Q.empty()){
		int r = Q.front().st, S = Q.front().nd;
		Q.pop();
		
		for(int i = 0; i < 10; ++i){
			int nxt = (r * 10 + i)%d, nxtS = S + i;
			if(nxtS <= s && !vis[nxt][nxtS]){
				vis[nxt][nxtS] = true;
				Q.push({nxt, nxtS});

				p[nxt][nxtS] = {r, S};
				res[nxt][nxtS] = i;
			}
		}
	}
	
	if(!vis[0][s]){
		puts("-1");
		return 0;
	}
	
	string ret;
	PII cur = {0, s};
	
	while(cur != make_pair(0, 0)){
		ret.push_back(res[cur.st][cur.nd] + '0');
		cur = p[cur.st][cur.nd];
	}
	
	reverse(ret.begin(), ret.end());
	cout << ret;
	return 0;
}