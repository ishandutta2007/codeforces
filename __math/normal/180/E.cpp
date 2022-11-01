#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int,int> Pii;


int main() {

	int n,m,k;
	cin>>n>>m>>k;
	vector< vector<int> > col(m);
	for(int i =0 ; i < n; i++){
		int x; cin>>x;
		col[x-1].push_back(i);
	}

	int ans = 0;
	for(int i = 0; i < m; i++){
		vector<int> b(col[i].size());
		for(int j = 1; j < (int)b.size(); j++){
			b[j] = b[j-1] + (col[i][j] - col[i][j-1] - 1);
		}
		int r = 0;
		for(int l = 0; l < (int)b.size(); l++){
			while(r < (int)b.size() && b[r] - b[l] <= k)
				r++;
			ans = max(ans,r - l);
		}
	}

	cout << ans << endl;

	return 0;
}