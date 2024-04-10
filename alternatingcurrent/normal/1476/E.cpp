#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, m, k;
map<string, int> pat;
pair<int, string> q[100100];
vector<int> q_match[100100];

vector<int> v[100100];
int deg[100100];
int ans[100100];
int cnt = 0;

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	rep(i, n){
		string s;
		cin >> s;
		pat[s] = i;
	}
	rep(i, m){
		cin >> q[i].second >> q[i].first;
		q[i].first--;
	}
	sort(q, q + m);
	rep(i, m){
		bool ok = 0;
		rep(mask, 1 << k){
			string res;
			rep(j, k)
				if(mask & (1 << j)) res += q[i].second[j];
				else res += '_';
			if(pat.count(res)){
				q_match[i].push_back(pat[res]);
				if(pat[res] == q[i].first) ok = 1;
			}
		}
		if(!ok){
			cout << "NO" << endl;
			return 0;
		}
		rep(j, (int)q_match[i].size()){
			if(q_match[i][j] != q[i].first) v[q[i].first].push_back(q_match[i][j]), deg[q_match[i][j]]++;
		}
	}
	queue<int> q;
	rep(i, n){
		if(deg[i] == 0) q.push(i);
	}
	while(!q.empty()){
		int now = q.front(); q.pop();
		ans[cnt++] = now;
		rep(i, (int)v[now].size()){
			deg[v[now][i]]--;
			if(deg[v[now][i]] == 0) q.push(v[now][i]);
		}
	}
	if(cnt < n){
		cout << "NO" << endl; 
	} else {
		cout << "YES" << endl;
		rep(i, n) cout << ans[i]+1 << " ";
		cout << endl;
	}
	return 0;
}