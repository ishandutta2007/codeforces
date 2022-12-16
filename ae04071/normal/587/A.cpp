#include <bits/stdc++.h>
using namespace std;

const int MAXN=1000000;
int n,arr[MAXN],val[MAXN*2+1];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",arr+i),val[arr[i]]++;

	int cnt=0;
	for(int i=0;i<MAXN+MAXN;i++) {
		cnt += val[i-1];
		val[i+1] += val[i]/2;
		val[i]%=2;
	}
	printf("%d\n",cnt);

	return 0;
}