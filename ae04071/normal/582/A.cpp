#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;

int n,a[250000];
int main() {
	scanf("%d",&n);
	for(int i=0;i<n*n;i++)scanf("%d",a+i);
	
	vector<int> res;
	sort(a,a+n*n);

	map<int, int> nd;
	for(int i=n*n-1;i>=0;i--) {
		if(nd.count(a[i]) && nd[a[i]]!=0) {
			nd[a[i]]-=1;
			continue;
		}
		for(auto &v:res) nd[__gcd(v,a[i])]+=2;
		res.push_back(a[i]);
	}
	for(auto &v:res)printf("%d ",v);

	return 0;
}