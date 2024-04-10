#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, k;
int par[300300];
int pre[300300], nxt[300300];
vector<int> v[300300];
int cnt = 0;
int deg[300300];
vector<int> ord;
int in[300300];
vector<int> cc[300300];

void trop_sort(){
//	cout << "????" << endl;
	ord.clear();
	memset(deg, 0, sizeof(deg));
	rep(i, cnt) rep(j, (int)v[i].size()) deg[v[i][j]]++;
	queue<int> q;
	rep(i, cnt) if(!deg[i]) q.push(i);
	while(!q.empty()){
		int now = q.front(); q.pop();
//		cout << "trop: " << now << endl;
		ord.push_back(now);
		rep(i, (int)v[now].size()){
			deg[v[now][i]]--;
			if(deg[v[now][i]] == 0) q.push(v[now][i]);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	rep(i, n) cin >> par[i], par[i]--;
	bool ok = 1;
	memset(pre, -1, sizeof(pre));
	memset(nxt, -1, sizeof(nxt));
	rep(i, k){
		int a, b;
		cin >> a >> b;
		a--, b--;
		if(nxt[a] >= 0 || pre[b] >= 0){
			ok = 0;
			break;
		} else {
			nxt[a] = b;
			pre[b] = a;
		}
	}
	if(!ok){
		cout << "0" << endl;
		return 0;
	}
	cnt = n;
	rep(i, n) if(par[i] >= 0) v[par[i]].push_back(i);
	rep(i, n) if(nxt[i] >= 0) v[i].push_back(nxt[i]);
	trop_sort();
	rep(i, n) v[i].clear();
	if((int)ord.size() < n){
		cout << "0" << endl;
		return 0;
	}
	cnt = 0;
	memset(in, -1, sizeof(in));
	rep(i, n){
//		cout << i << endl;
		if(in[i] < 0){
			int now = i;
			while(pre[now] >= 0) now = pre[now];
			in[now] = cnt;
			cc[cnt].push_back(now);
			while(nxt[now] >= 0){
				now = nxt[now];
				cc[cnt].push_back(now);
				in[now] = cnt;
			}
			cnt++;
		}
	}
	rep(i, n) if(par[i] >= 0 && in[par[i]] != in[i]) v[in[par[i]]].push_back(in[i]);
	trop_sort();
//	cout << "???" << endl;
	if((int)ord.size() < cnt){
		cout << "0" << endl;
		return 0;
	}
	rep(i, (int)ord.size()){
		rep(j, (int)cc[ord[i]].size()) cout << cc[ord[i]][j] + 1 << " ";
	}
	cout << endl;
	return 0;
}