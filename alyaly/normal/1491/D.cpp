#include<bits/stdc++.h>
#define int long long
#define N 200000
using namespace std;
int T,n,m,ans1,ans2,ffl;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>m;ans1=ans2=ffl=0;
		for(int i=0;i<=30;i++){
			if(n&(1<<i))ans1++;
			if(m&(1<<i))ans2++;
			if(ans1<ans2)ffl=1;
		}
		if(n<=m&&!ffl)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
/*

*/