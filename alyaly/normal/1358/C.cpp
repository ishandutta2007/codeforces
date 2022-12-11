#include<bits/stdc++.h>
//#pragma GCC optimize(2)
#define int long long
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
int T,n,a[200001],ans,xa,ya,xb,yb;
signed main(){
	cin>>T;
	while(T--){
		cin>>xa>>ya>>xb>>yb;
		printf("%lld\n",(xb-xa)*(yb-ya)+1);
	}
	return 0;
}
/*

*/