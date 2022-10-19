#include <iostream>
#include <map>
#include <vector>
using namespace std;

int gcd(int a, int b){
	while(b) b^=a^=b^=a%=b;
	return a;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> w;
	vector<int> b;
	vector<int> a;
	vector<int> t;
	int dp[1001][1001];
	map<int, vector<int> > q;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		w.push_back(x);
	}
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		b.push_back(x);
		a.push_back(i);
		
	}
	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		int z = a[y];
		
		for(int j=0; j<n; j++){
			
			if(a[j]==z){
				a[j] = a[x];
			}
		}
	}
	for(int i=0; i<n; i++){
		//cout << a[i] << endl;
		q[a[i]].push_back(i);
		if(q[a[i]].size()==1){
			t.push_back(a[i]);
		}
	}
	for(int j=0; j<=t.size(); j++){
		for(int i = 0; i<=k; i++){
			dp[i][j] = -1000000000;
			if(j==0){
				dp[i][j] = 0;
				
			}
			else{
				int tw = 0;
				int tb = 0;
				dp[i][j] = dp[i][j-1];
				for(int p=0; p<q[t[j-1]].size();p++){
					if(i>=w[q[t[j-1]][p]] && dp[i-w[q[t[j-1]][p]]][j-1] + b[q[t[j-1]][p]]> dp[i][j]) {
						dp[i][j] = dp[i-w[q[t[j-1]][p]]][j-1] + b[q[t[j-1]][p]];
					}
					tb += b[q[t[j-1]][p]];
					tw += w[q[t[j-1]][p]];
				}
				if(i>=tw && dp[i-tw][j-1] + tb > dp[i][j]){
					dp[i][j] = dp[i-tw][j-1] + tb;
				}
			}
		}
	}
	cout << dp[k][t.size()] << endl;
}