# include <bits/stdc++.h>

using namespace std;

const int xn = 1e2+10;
int dp[xn][xn];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int n;
	cin >> n;
	vector <int> a, b;
	int q, w;
	for (int i=0; i<n; i++){
		cin >> q >> w;
		if (q == 1) a.push_back(w);
		else b.push_back(w);
	}
	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end(), cmp);
	for (int i=0; i<=a.size(); i++){
		for (int j=0; j<=b.size(); j++){
			int s = i + j*2;
			int g = 0;
			for (int k=i; k<a.size(); k++) g += a[k];
			for (int k=j; k<b.size(); k++) g += b[k];
			if (s >= g) dp[i][j] = i + j*2;
			else dp[i][j] = 1e9+10;
		}
	}
	int mn = 1e9+10;
	for (int i=0; i<=a.size(); i++){
		for (int j=0; j<=b.size(); j++) mn = min(mn, dp[i][j]);
	}
	cout << mn << endl;
}