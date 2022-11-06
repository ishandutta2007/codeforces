#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)

int main(){
	int n, a[int(2e5+3)],b;
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%d",&b);
		a[b-1] = i;
	}
	long long ans = 0;
	rep(i,0,n-1) ans += abs(a[i]-a[i+1]);
	cout << ans << endl;
}