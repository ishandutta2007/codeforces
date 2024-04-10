#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
using pii=pair<int,int>;
using lli = long long;

int n,a[500000];
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);

	int ans=0;
	for(int i=0,j;i<n;i=j) {
		for(j=i+1;j<n && a[j]!=a[j-1];j++);
		ans = max(ans,(j-i-1)/2);
		for(int k=i+1;k<j;k++) {
			if((j-i)&1) {
				a[k] = a[i];
			} else {
				if(k-i <= (j-i-1)/2) a[k] = a[i];
				else a[k] = a[j-1];
			}
		}
	}
	printf("%d\n",ans);
	for(int i=0;i<n;i++) printf("%d ",a[i]);
	
	return 0;
}