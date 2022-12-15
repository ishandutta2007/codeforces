#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using lli = long long;

int n,a[1000];
inline int _abs(int a) {return a<0 ? -a : a;}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);

	int ans=1e9,v=0;
	for(int t=1;t<=100;t++) {
		int s=0;
		for(int i=0;i<n;i++) s += min({_abs(a[i]-t+1),_abs(a[i]-t-1),_abs(a[i]-t)});
		if(s<ans) {
			v=t;
			ans=s;
		}
	}
	printf("%d %d\n",v,ans);


	return 0;
}