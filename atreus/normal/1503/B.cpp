#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int,int>> B, W;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if ((i+j)&1)
				B.push_back({i,j});
			else
				W.push_back({i,j});
		}
	}
	int ptrB = 0, ptrW = 0; 
	int count = n*n;
	while (count--){
		int c;
		cin >> c;
		if (c != 1){
			int x = B[ptrB].first;
			int y = B[ptrB].second;
			cout << 1 << " " << x << " " << y << endl;
			ptrB++;
			if (ptrB == B.size())
				break;
		}
		else{
			int x = W[ptrW].first;
			int y = W[ptrW].second;
			cout << 2 << " " << x << " " << y << endl;
			ptrW++;
			if (ptrW == W.size())
				break;
		}
	}
	if (ptrB == B.size()){
		while (count--){
			int c;
			cin >> c;
			if (c != 2)
				cout << 2 << " " << W[ptrW].first << " " << W[ptrW++].second << endl;
			else
				cout << 3 << " " << W[ptrW].first << " " << W[ptrW++].second << endl;
		}
	}
	else{	
		while (count--){
			int c;
			cin >> c;
			if (c != 1)
				cout << 1 << " " << B[ptrB].first << " " << B[ptrB++].second << endl;
			else
				cout << 3 << " " << B[ptrB].first << " " << B[ptrB++].second << endl;
		}
	}
}