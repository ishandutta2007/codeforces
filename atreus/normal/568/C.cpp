/**
 *    author:  Atreus
 *    created: 21.01.2019
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 400 + 10; 

int n, c, C;
int com[maxn];
bool visited[maxn];
vector<int> in[maxn], out[maxn];
vector<int> topol;

void dfs2(int v){
	com[v] = c;
	for (auto u : in[v])
		if (com[u] <= C)
			dfs2(u);
}

void dfs(int v){
	visited[v] ^= 1;
	for (auto u : out[v])
		if (visited[u] != visited[v])
			dfs(u);
	topol.push_back(v);
}

inline bool haveanswer(){
	bool now = visited[0];
	C = c;
	c ++;
	for (int v = 0; v <= 2 * n + 1; v++){
		if (visited[v] == now){
			dfs(v);
		}
	}
	reverse(topol.begin(), topol.end());
	for (auto v : topol){
		if (com[v] <= C){
			dfs2(v);
			c ++;
		}
	}
	for (int i = 0; i <= n; i++)
		if (com[2 * i + 0] == com[2 * i + 1])
			return 0;
	return 1;
}

inline void add(int fi, int se){
	out[fi ^ 1].push_back(se);
	out[se ^ 1].push_back(fi);
	in[se].push_back(fi ^ 1);
	in[fi].push_back(se ^ 1);
}

inline void del(int fi, int se){
	out[fi ^ 1].pop_back();
	out[se ^ 1].pop_back();
	in[se].pop_back();
	in[fi].pop_back();
}

int szout[maxn], szin[maxn];

void solve(int, string);

string s;

int main(){
	ios_base::sync_with_stdio(false);
	string vc;
	cin >> vc;
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;
		char c, d;
		cin >> a >> c >> b >> d;
		a --, b --;
		add(2 * a + (c == 'V'), 2 * b + (d == 'C'));
	}
	for (int i = 0; i <= 2 * n + 1; i++){
		szout[i] = out[i].size();
		szin[i] = in[i].size();
	}
	cin >> s;
	if (!haveanswer())
		return cout << -1 << endl, 0;
	for (int j = n - 1; j >= -1; j--){
		for (int i = 0; i <= 2 * n + 1; i++){
			while (szout[i] < out[i].size())
				out[i].pop_back();
			while (szin[i] < in[i].size())
				in[i].pop_back();
		}
		bool notgood = 0;
		for (int i = 0; i < n; i++){
			int lb = int(s[i] - 'a');
			int ub = int(s[i] - 'a') + 1;
			if (i > j){
				ub = vc.size();
				if (i == j + 1)
					lb ++;
				else
					lb = 0;
			}
			bool isC = 0, isV = 0;
			for (int k = lb; (!isC or !isV) and k < ub; k++){
				if (vc[k] == 'C' and isC)
					continue;
				if (vc[k] == 'V' and isV)
					continue;
				if (vc[k] == 'C')
					isC = 1;
				else
					isV = 1;
			}
			if (!isC){
				if (!isV){
					notgood = 1;
					break;
				}
				else{
					add(2 * i + 0, 2 * i + 0);
				}
			}
			else{
				if (!isV)
					add(2 * i + 1, 2 * i + 1);
			}
		}
		if (!notgood and haveanswer()){
			solve(j, vc);
			return 0;
		}
	}
	cout << -1 << endl;
}

void solve(int j, string vc){
	for (int i = 0; i <= 2 * n + 1; i++){
		while (szout[i] < out[i].size())
			out[i].pop_back();
		while (szin[i] < in[i].size())
			in[i].pop_back();
	}
	string t;
	for (int i = 0; i < n; i++){
		int lb = int(s[i] - 'a');
		int ub = int(s[i] - 'a') + 1;
		if (i > j){
			ub = vc.size();
			if (i == j + 1)
				lb ++;
			else
				lb = 0;
		}
		bool found = 0;
		bool isC = 0, isV = 0;
		for (int k = lb; (!isC or !isV) and k < ub; k++){
			if (vc[k] == 'C' and isC)
				continue;
			if (vc[k] == 'V' and isV)
				continue;
			if (vc[k] == 'C')
				isC = 1;
			else
				isV = 1;

			add(2 * i + (vc[k] == 'C'), 2 * i + (vc[k] == 'C'));
			if (haveanswer()){
				found = 1;
				t += char(k + 'a');
				break;
			}
			else
				del(2 * i + (vc[k] == 'C'), 2 * i + (vc[k] == 'C'));
		}
	}
	cout << t << endl;
}