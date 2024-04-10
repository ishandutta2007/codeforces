#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int a[maxn], par[maxn];

int get_par(int v){
	return par[v] < 0 ? v : par[v] = get_par(par[v]);
}

void merge(int v, int u){
	if ((v = get_par(v)) == (u = get_par(u)))
		return;
	par[v] = u;
}

vector<pair<int,int>> ops;

void doop(int i, int j){
	if (i == j)
		assert(false);
	ops.push_back({i,j});
	swap(a[i],a[j]);
	a[i] = -a[i], a[j] = -a[j];
}

int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	memset(par, -1, sizeof par);
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		merge(i,a[i]);
	}
	int pre = -1;
	for (int i = 1; i <= n; i++){
		if (get_par(i) != i or a[i] == i)
			continue;
		if (pre != -1){
			doop(i,pre);
			pre = -1;
			continue;
		}
		pre = i;
	}
	if (pre != -1){
		if (pre == a[a[pre]]){
			for (int i = 1; i <= n; i++){
				if (i != pre and i != a[pre]){
					int prepre = a[pre];
					doop(i,pre);
					doop(i,prepre);
					doop(i,pre);
					break;
				}
			}
		}
		else{
			int x = pre;
			int y = a[x];
			int z = a[y];
			doop(x,y);
			doop(y,z);
		}
	}
	for (int i = 1; i <= n; i++){	
		while (a[i] < 0 and abs(a[i]) != i and a[abs(a[i])] > 0){
			int y = abs(a[i]);
			doop(i,y);
		}
	}
	for (int i = 1; i <= n; i++)
		if (a[i] < 0 and abs(a[i]) != i)
			doop(i,abs(a[i]));
	cout << ops.size() << endl;
	for (auto [x,y] : ops)
		cout << x << " " << y << '\n';
}