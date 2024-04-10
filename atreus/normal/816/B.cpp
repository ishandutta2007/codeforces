#include <iostream>

using namespace std;

const int maxn = 2e5 + 500;

int par[maxn], mark[maxn], much[maxn];
bool admis[maxn];

int main(){
	int n, k, q;
	cin >> n >> k >> q;
	for (int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		mark[a] ++;
		mark[++b] --;
	}
	for (int i = 1; i <= maxn; i++)
		much[i] = much[i - 1] + mark[i];
	for (int i = 1; i <= maxn; i++)
		if (much[i] >= k)
			admis[i] = true;
	for (int i = 1; i <= maxn; i++)
		par[i] = par[i - 1] + admis[i];
	for (int i = 0; i < q; i++){
		int a, b;
		cin >> a >> b;
		cout << par[b] - par[--a] << " ";
	}
}