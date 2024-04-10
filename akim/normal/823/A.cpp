#include <bits/stdc++.h>

#define f first
#define s second 
#define mp make_pair
#define pb push_back
#define ll long long

using namespace std;

const int N = (int)3e5;

int n,k, a[N], an;
vector <int> g[N];

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 2; i <= k + 1; i++){
		g[i].pb(i);
	}
	int j = 2;
	for(int i = k + 2; i <= n; i++){
		g[j].pb(i);
		j++;
		if(j == k + 2){
			j = 2;
		}
	}
	for(int i = 2; i <= k + 1; i++){
		g[i].pb(1);
	}
	printf("%d\n", int(g[2].size()) + int(g[3].size()) - 2);
	for(int i = 2; i <= k + 1; i++){
		for(int j = 1; j < g[i].size(); j++){
			printf("%d %d\n", g[i][j - 1], g[i][j]);
		}
	}


return 0;
}