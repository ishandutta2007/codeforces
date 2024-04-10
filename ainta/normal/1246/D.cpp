#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 101000
#define pii pair<int,int>
using namespace std;
int n, H[N_], D[N_], D2[N_];
vector<int>E[N_], Res, Ch[N_];
void DFS(int a) {
	vector<pii>V;
	for (auto &x : E[a]) {
		DFS(x);
		V.push_back({ H[x],x });
		H[a] = max(H[a], H[x] + 1);
	}
	sort(V.begin(), V.end());
	for (auto &t : V) {
		Ch[a].push_back(t.second);
	}
	for (int i = 1; i < V.size(); i++) {
		for (int j = 0; j < V[i - 1].first+1; j++) {
			Res.push_back(V[i].second);
		}
	}
}
void Print(int a) {
	printf("%d ", a);
	for (auto &x : Ch[a]) {
		Print(x);
	}
}
int main(){
	int i, a;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d", &a);
		E[a].push_back(i);
	}
	DFS(0);
	Print(0);
	printf("\n%d\n",Res.size());
	for (auto &t : Res)printf("%d ", t);
}