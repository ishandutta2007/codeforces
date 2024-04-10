#include<bits/stdc++.h>
//#pragma GCC optimize(2)
//#define int long long
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
int T,n,m;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		if(n%2==0||m%2==0) printf("%d\n",m*n/2);
		else printf("%d\n",min((n-1)*m/2+(m+1)/2,(m-1)*n/2+(n+1)/2));
	}
	return 0;
}
/*

*/