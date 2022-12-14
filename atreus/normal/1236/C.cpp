#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

vector<int> a[500];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	
	for (int i = 1; i <= n*n; i += n){
		if ((i / n) & 1)
			for (int j = 1; j <= n; j++)
				a[j].push_back(i + j - 1);
		else
			for (int j = 1; j <= n; j++)
				a[j].push_back(i + (n-j));
	}
	for (int i = 1; i <= n; i++){
		for (auto it : a[i])
			cout << it << " ";
		cout << endl;
	}
}