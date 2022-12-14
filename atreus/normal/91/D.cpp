#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;

struct Operation{
	int k;
	vector<int> b;
	vector<int> c;
};

vector<Operation> a;
vector<int> b;
bool visited[maxn];
int p[maxn];

void dfs(int v){
	if (visited[v])
		return;
	visited[v] = 1;
	b.push_back(v);
	dfs(p[v]);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	vector<vector<int> > al2, al3;
	for (int i = 1; i <= n; i++){
		if (visited[i])
			continue;
		dfs(i);
		while (b.size() >= 4){
			int bs = 5;
			vector<int> t;
			while (b.size() && bs --){
				t.push_back(b.back());
				b.pop_back();
			}
			reverse(t.begin(), t.end());
			Operation now;
			now.k = t.size();
			now.b = t;	
			int tmp = p[t[now.k - 1]];
			for (int i = now.k - 1; i >= 1; i--)	
				p[t[i]] = p[now.b[i - 1]];
			p[t[0]] = tmp;
			t.push_back(t[0]);
			t.erase(t.begin() + 0);
			now.c = t;
			a.push_back(now);
			if (now.k == 5)
				b.push_back(now.c.back());
		}
		if (b.size() == 2)	
			al2.push_back(b);
		if (b.size() == 3)
			al3.push_back(b);
		b.clear();
	}
	while (!al2.empty() or !al3.empty()){
		if (!al2.empty() and !al3.empty()){
			vector<int> fi = al2.back();
			vector<int> se = al3.back();
			al2.pop_back();
			al3.pop_back();
			Operation now;
			now.k = 5;
			for (auto idx : fi)
				now.b.push_back(idx);
			for (auto idx : se)
				now.b.push_back(idx);
			now.c = now.b;
			swap(now.c[0], now.c[1]);
			swap(now.c[2], now.c[3]);
			swap(now.c[3], now.c[4]);
			a.push_back(now);
		}
		else if (!al2.empty()){
			vector<int> fi = al2.back();
			al2.pop_back();
			vector<int> se;
			if (!al2.empty()){
				se = al2.back();
				al2.pop_back();
			}
			Operation now;
			now.k = fi.size() + se.size();
			for (auto it : fi)
				now.b.push_back(it);
			for (auto it : se)
				now.b.push_back(it);
			now.c = now.b;
			swap(now.c[0], now.c[1]);
			if (now.k == 4)
				swap(now.c[2], now.c[3]);
			a.push_back(now);
		}
		else{
			vector<int> fi = al3.back();
			al3.pop_back();
			if (al3.empty()){
				Operation now;
				now.k = 3;
				now.b = fi;
				now.c = now.b;
				swap(now.c[0], now.c[1]);
				swap(now.c[1], now.c[2]);
				a.push_back(now);
				break;
			}
			vector<int> se = al3.back();
			al3.pop_back();
			Operation now;
			now.k = 5;
			for (auto it : fi)
				now.b.push_back(it);
			for (auto it : se)
				now.b.push_back(it);
			now.b.pop_back();
			now.c = now.b;
			swap(now.c[0], now.c[1]);
			swap(now.c[1], now.c[2]);
			swap(now.c[4], now.c[3]);
			a.push_back(now);
			se.erase(se.begin() + 1);
			al2.push_back(se);
		}
	}
	cout << a.size() << endl;
	for (auto op : a){
		cout << op.k << endl;
		for (auto it : op.b)
			cout << it << " ";
		cout << endl;
		for (auto it : op.c)
			cout << it << " ";
		cout << endl;
	}
}