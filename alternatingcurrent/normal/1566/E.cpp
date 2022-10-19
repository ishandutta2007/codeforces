#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
vector<int> v[200200];
bool isbud[200200];
int leafson[200200];
int sumleafson[200200];
int sumleafreal[200200];
int sumbud[200200];
int sumleafpar[200200];
int sumsumleaf, sumsumbud;
void dfs0(int now, int par){
	bool isleaf = 1;
	leafson[now] = sumleafreal[now] = 0;
//	if(par >= 0 && (int)v[now].size() == 1)
//		sumsumleaf++;
	rep(i, (int)v[now].size())
		if(v[now][i] != par){
			dfs0(v[now][i], now);
			sumleafreal[now] += (int)v[v[now][i]].size() == 1;
			isleaf &= isbud[v[now][i]];
			leafson[now] += !isbud[v[now][i]];
		}
	isbud[now] = !isleaf;
	sumsumleaf += isleaf;
	sumsumbud += isbud[now];
	sumleafpar[now] = isleaf;
}
void dfs1(int now, int par){
	sumleafson[now] = leafson[now];
	sumbud[now] = isbud[now];
	if(par >= 0)
		sumleafson[now] += sumleafson[par], sumleafreal[now] += sumleafreal[par], sumbud[now] += sumbud[par], sumleafpar[now] += sumleafpar[par];
	rep(i, (int)v[now].size())
		if(v[now][i] != par)
			dfs1(v[now][i], now);
}

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			v[i].clear();
		rep(i, n - 1){
			int a, b;
			cin >> a >> b;
			a--, b--;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		sumsumleaf = sumsumbud = 0;
		dfs0(0, -1);
		dfs1(0, -1);
		int ans = sumsumleaf;
		for(int i = 1; i < n; i++){
			if((int)v[i].size() == 1){
				ans = min(ans, sumsumleaf - (sumleafpar[i] - 1) - (sumsumbud - sumbud[i]));
			}
		}
		cout << ans << endl;
	}
	return 0;
}