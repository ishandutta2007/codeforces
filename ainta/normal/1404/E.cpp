#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m, AA, BB, CC;

namespace MF{
	const int MV = 300200;
	const int ME = 500400;
	const int INF = 1e9;
	int dis[MV];
	int st[MV], en[ME<<1], nxt[ME<<1], flow[ME<<1], ce;
	int start[MV];
	void init() {
		memset(st, 0, sizeof st);
		ce = 1;
	}
	void addE(int s, int e, int f = 1) {
		++ce; nxt[ce] = st[s]; st[s] = ce; en[ce] = e; flow[ce] = f;
		++ce; nxt[ce] = st[e]; st[e] = ce; en[ce] = s; flow[ce] = 0;
	}
	int que[MV];
	int bfs(int N, int S, int E) {
		for(int i=1;i<=N;i++) dis[i] = -1;
		dis[S] = 0;
		int *fr = que, *re = que;
		*fr++ = S;
		while(fr != re) {
			int t = *re++;
			for(int i=st[t];i;i=nxt[i]) if(flow[i] > 0 && dis[en[i]] == -1) {
				dis[en[i]] = dis[t] + 1;
				*fr++ = en[i];
			}
		}
		return dis[E] != -1;
	}
	
	int dfs(int x, int E, int f) {
		if(x == E) return f;
		for(int &i=start[x],t;i;i=nxt[i]) if(flow[i] > 0 && dis[en[i]] == dis[x] + 1 && (t = dfs(en[i], E, min(f, flow[i]))) > 0){
			flow[i] -= t;
			flow[i^1] += t;
			return t;
		}
		return 0;
	}
	
	int Get(int N, int S, int E) {
		int res = 0;
		while(bfs(N, S, E)) {
			for(int i=1;i<=N;i++) start[i] = st[i];
			while(1) {
				int t = dfs(S, E, INF);
				if(t == 0) break;
				res += t;
			}
		}
		return res;
	}

}

char p[210][210];

int Num(int x, int y){
    return x*m+y + 3;
}

int main(){
    int i, j, INF = 1e8;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s",p[i]);
    }
    int source = 1, sink = 2;
    MF::init();
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(p[i][j]=='#'){
                if(p[i+1][j]=='#'){
                    MF::addE(Num(i+1,j),Num(i,j), 1);
                }
                else{
                    MF::addE(source,Num(i,j), 1);
                }
                if(p[i][j+1]=='#'){
                    MF::addE(Num(i,j),Num(i,j+1), 1);
                }
                else{
                    MF::addE(Num(i,j),sink, 1);
                }
            }
        }
    }
    printf("%d\n",MF::Get(n*m+5,source,sink));
}