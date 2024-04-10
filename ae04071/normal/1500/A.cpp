#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;

int n;
pii arr[200000];
pii cand[2500001][2];

bool cmp(pii a, pii b) {
	return a.fi!=b.fi && a.fi!=b.se && a.se!=b.fi && a.se!=b.se;
}

void print(pii a, pii b) {
	printf("YES\n%d %d %d %d\n",arr[a.fi].se, arr[b.se].se, arr[a.se].se, arr[b.fi].se);
}

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i].fi), arr[i].se = i + 1;
	sort(arr, arr+n);

	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			int diff = arr[j].fi - arr[i].fi;
			if(cand[diff][0].se == 0) {
				cand[diff][0] = pii(i, j);
			} else {
				if(cmp(cand[diff][0], pii(i, j))) {
					print(cand[diff][0], {i,j});
					return 0;
				} else {
					if(cand[diff][1].se == 0) {
						cand[diff][1] = pii(i, j);
					} else if(cmp(cand[diff][0], pii(i, j))) {
						print(cand[diff][1], {i,j});
						return 0;
					}
				}
			}
		}
	}
	puts("NO");

	return 0;
}