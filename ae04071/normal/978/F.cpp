#include <bits/stdc++.h>

using namespace std;
typedef long long lli;
const lli inf=1e15;

int n,m;
vector<int> adj[200001];
int arr[200001];

int main() {
	scanf("%d%d",&n,&m);

	vector<int> t;
	for(int i=1;i<=n;i++) {
		scanf("%d",arr+i);
		t.push_back(arr[i]);
	}
	sort(t.begin(),t.end());
	for(int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1;i<=n;i++) {
		int c=lower_bound(t.begin(),t.end(),arr[i])-t.begin();
		for(auto &it:adj[i]) if(arr[it]<arr[i]) c--;
		printf("%d ",c);
	}
	return 0;
}