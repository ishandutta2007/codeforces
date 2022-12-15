#include <bits/stdc++.h>
using namespace std;

struct node {
	map<int, node*> next;
	queue<int> cand;
	node() {}
}*root;

int n,m,a[1500][1500],b[1500][1500];
int ai[1500],bi[1500];

bool cmpa(int i,int j) {
	for(int k=0;k<m;k++) {
		if(a[i][k] != a[j][k]) return a[i][k] < a[j][k];
	}
	return i < j;
}
bool cmpb(int i,int j) {
	for(int k=0;k<m;k++) {
		if(b[i][k] != b[j][k]) return b[i][k] < b[j][k];
	}
	return i < j;
}


int chk[1500], lck[1500], ali[1500];
int main() {
	root = new node();
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) scanf("%d",&b[i][j]);
	}
	for(int i=0;i<n;i++) ai[i]=i, bi[i]=i;
	sort(ai, ai+n, cmpa);
	sort(bi, bi+n, cmpb);
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) if(a[ai[i]][j] != b[bi[i]][j]) {
			puts("-1");
			return 0;
		}
		ali[bi[i]] = ai[i];
	}

	for(int i=0;i<n-1;i++) {
		for(int j=0;j<m;j++) {
			if(b[i][j] > b[i+1][j]) lck[j]++;
		}
	}
	queue<int> que;
	for(int j=0;j<m;j++) if(!lck[j]) que.push(j);
	
	vector<int> ans;
	while(!que.empty()) {
		int c = que.front();que.pop();
		ans.push_back(c+1);

		for(int i=0;i<n-1;i++) if(!chk[i] && b[i][c] < b[i+1][c]) {
			chk[i] = 1;
			for(int j=0;j<m;j++) if(b[i][j] > b[i+1][j]) {
				lck[j]--;
				if(lck[j] == 0) que.push(j);
			}
		}
	}

	for(int i=0;i<n-1;i++) {
		if(!chk[i] && ali[i] > ali[i+1]) {
			puts("-1");
			return 0;
		}
	}
	
	printf("%lu\n", ans.size());
	reverse(ans.begin(),ans.end());
	for(auto &v:ans) printf("%d ",v);
	
	return 0;
}