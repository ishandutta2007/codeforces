#include<bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define PII pair <int, int>

const int N = 1007;

int n;
string s;
int d[N];
bool vis[N];
int place[N][N];
vector <PII> res;
vector <set <int> > V[N];

int closest(int x){
	while(s[x] >= '0' && s[x] <= '9')
		++x;
	return x;
}

int number(int u){
	int ret = 0;
	while(s[u] >= '0' && s[u] <= '9'){
		ret *= 10, ret += s[u] - '0';
		++u;
	}
	
	return ret;
}

void change(int v){
	cin >> s;
	s = s + '-';
	
	int i = 0;
	while(i + 1 < s.size()){
		while(s[i] != ':')
			++i;
		++i;
		
		set <int> S;
		while(s[i - 1] != '-'){
			int x = number(i);
			S.insert(x);
			place[x][v] = V[v].size();
			i = closest(i) + 1;
		}
		
		V[v].pb(S);
	}
}

void solve(){
	while(true){
		int l1 = -1, l2 = -1;
		for(int i = 1; i <= n; ++i){
			if(vis[i])
				continue;
			
			for(int j = 0; j < V[i].size(); ++j)
				if(V[i][j].size() == 1){
					l1 = i;
					l2 = *V[i][j].begin();
					break;
				}
			
			if(l1 != -1)
				break;
		}
		
		if(l1 == -1)
			break;
		
		vis[l2] = true;
		res.pb({l1, l2});
		d[l1]++, d[l2]++;
		for(int i = 1; i <= n; ++i){
			if(vis[i])	continue;
			V[i][place[l2][i]].erase(l2);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i)
		change(i);
	solve();
	
	if(res.size() < n - 1){
		puts("-1");
		return 0;
	}
	
	for(int i = 1; i <= n; ++i)
		if(d[i] != V[i].size()){
			puts("-1");
			return 0;
		}
	
	printf("%d\n", n - 1);
	for(auto v: res)
		printf("%d %d\n", v.st, v.nd);
	return 0;
}