#include<bits/stdc++.h>
using namespace std;

int T , N , M , ed[65][65] , id[65][65] , p[260] , q[260] , w[260] , ans[260];
struct dat{
	int arr[263]; dat(){memset(arr , 0 , sizeof(arr));}
	friend void operator +=(dat &p , dat q){for(int i = 1 ; i <= M + 1 ; ++i) p.arr[i] = (p.arr[i] + 3 - q.arr[i]) % 3;}
	void turn(int x){if(arr[x] != 1){for(int i = 1 ; i <= M + 1 ; ++i) arr[i] = arr[i] ? 3 - arr[i] : 0;}}
};
struct base{
	dat pot[263]; bool vis[263]; base(){memset(vis , 0 , sizeof(vis));}
	void ins(dat x){
		for(int i = 1 ; i <= M + 1 ; ++i)
			if(x.arr[i]){x.turn(i); if(vis[i]) x += pot[i]; else{vis[i] = 1; pot[i] = x; return;}}
	}
};

signed main(){
	for(cin >> T ; T ; --T){
		cin >> N >> M; memset(ed , 0 , sizeof(ed)); memset(id , 0 , sizeof(id));
		for(int i = 1 ; i <= M ; ++i){
			int p , q , w;
			cin >> p >> q >> w; ed[p][q] = ed[q][p] = w; id[p][q] = id[q][p] = i;
			::p[i] = p; ::q[i] = q; ::w[i] = w;
		}
		base T;
		for(int i = 1 ; i <= N ; ++i)
			for(int j = i + 1 ; j <= N ; ++j)
				for(int k = j + 1 ; k <= N ; ++k)
					if(id[i][j] && id[j][k] && id[i][k]){dat temp; temp.arr[id[i][j]] = temp.arr[id[i][k]] = temp.arr[id[j][k]] = 1; T.ins(temp);}
		for(int i = 1 ; i <= N ; ++i) for(int j = i + 1 ; j <= N ; ++j) if(id[i][j] && ed[i][j] != -1){dat temp; temp.arr[M + 1] = ed[i][j] % 3; temp.arr[id[i][j]] = 1; T.ins(temp);}
		if(T.vis[M + 1]) cout << -1 << endl;
		else{
			for(int i = M ; i ; --i){
				dat cur = T.pot[i]; int ans = cur.arr[M + 1];
				for(int j = i + 1 ; j <= M ; ++j) ans = ((ans - cur.arr[j] * ::ans[j]) % 3 + 3) % 3;
				::ans[i] = ans ? ans : ans + 3;
			}
			for(int i = 1 ; i <= M ; ++i) cout << ans[i] << ' ';
			cout << endl;
		}
	}
	return 0;
}