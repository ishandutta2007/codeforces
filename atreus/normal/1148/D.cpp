#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 10;

void print(vector<pair<pair<int, int>, int> > a, bool reverse){
	if (reverse == 0)
		sort(a.begin(), a.end(), greater<pair<pair<int, int>, int> >());
	else
		sort(a.begin(), a.end());
	cout << a.size() << endl;
	for (auto it : a)
		cout << it.second << " ";
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	vector<pair<pair<int, int>, int> > geq, leq;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int a, b;
		cin >> a >> b;
		if (a < b)
			leq.push_back({{a, b}, i});
		else
			geq.push_back({{b, a}, i});
	}
	if (leq.size() < geq.size())
		print(geq, 1);
	else
		print(leq, 0);
}