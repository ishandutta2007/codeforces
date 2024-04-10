#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 17;
int n, l[maxn], r[maxn];

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	vector<int> l0;
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
		if(l[i] == 0)
			l0.push_back(i);
	}
	for(int i = 1; i < l0.size(); i++){
		int j = l0[i - 1], k = l0[i];
		while(r[j] != 0)
			j = r[j];
		l[k] = j;
		r[j] = k;
	}
	for(int i = 1; i <= n; i++)
		cout << l[i] << ' ' << r[i] << '\n';
	return 0;
}