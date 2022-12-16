#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long lli;
typedef pair<int,int> pii;

bool isp(int val) {
	for(int i=2;i*i<=val;i++){
		if(val%i==0) return false;
	}
	return true;
}

int main() {
	int n;
	scanf("%d",&n);
	if(n==3 || n==5) printf("1\n%d\n",n);
	else {
		for(int i=2;;i++) if(isp(n-i)) {
			if(isp(i)) {
				printf("2\n%d %d\n",i,n-i);
				return 0;
			} else {
				for(int j=2;j<=i;j++) if(isp(i-j) && isp(j)) {
					printf("3\n%d %d %d\n",j,i-j, n-i);
					return 0;
				}
			}
		}
	}
	
	return 0;
}