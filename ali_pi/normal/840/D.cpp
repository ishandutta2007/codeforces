#include <bits/stdc++.h>

using namespace std;

random_device rd;
mt19937 mt(rd());
const int MAX = (3e5)+1;

int n, q, a[MAX];
vector<int> b[MAX];

int main() {
	scanf("%d%d",&n,&q);
	for(int i = 0; i < n; ++i) {
		scanf("%d",a+i);
		b[a[i]].push_back(i);
	}
	for(int l, r, k; q > 0; --q) {
		scanf("%d%d%d",&l,&r,&k); 
                --l; --r;
		int res = -1;
		for(int t = 0; t < 70; t++) {
			int x = a[l + mt() % (r-l+1)];
			int lb = lower_bound(b[x].begin(), b[x].end(), l) - b[x].begin();
			int rb = lb + (r-l+1)/k;
			if(lb == b[x].size() || rb >= b[x].size() || b[x][rb] > r) continue;
			res = (res == -1 || x < res ? x : res);
		}
		printf("%d\n",res);
	}
        return 0;
}