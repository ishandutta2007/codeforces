#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 2e6 + 5;

int mark[maxn];
vector<int> v;

int can(int m, int s){
	int k = ((m + s - 1) / s) * s - m;
	if (k <= (m + s - 1) / s)
		return (m + s - 1) / s;
	return -1;
}

void efraz(int m){
	for (int i = 2; i <= m + 1; i++)
		if (can(m, i) != -1)
			v.push_back(i);
}

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			mark[i] = 0;
		for (int i = 1; i <= n; i++){
			int x;
			cin >> x;
			mark[x] ++;
		}
		vector<int> a;
		for (int i = 1; i <= n; i++)
			if (mark[i] > 0)
				a.push_back(mark[i]);
		int mnm = *min_element(a.begin(), a.end());
		v.clear();
		efraz(mnm);
		int answer = n;
		int sz = v.size();
		for (int i = sz - 1; i >= 0; i--){
			bool flag = 1;
			int sum = 0;
			for (auto j : a){
				int p = can(j, v[i]);
				if (p == -1)
					flag = 0;
				else
					sum += p;
			}
			if (flag == 1)
				answer = min(answer, sum);
		}
		cout << answer << endl;
	}
}