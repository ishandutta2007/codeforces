#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

int n,arr[1000];
int val[1001];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",arr+i);
	}
	vector<int> v;
	for(int i=n-1;i>=0;i--) {
		if(val[arr[i]]) continue;
		v.push_back(arr[i]);
		val[arr[i]]=1;
	}
	printf("%d\n",v.size());
	for(int i=v.size()-1;i>=0;i--) printf("%d ",v[i]);
	return 0;
}