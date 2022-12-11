#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,fl[300001],nfl[300001],ans[300001],aans;
string s;
signed main(){
//	freopen("bag2.in","r",stdin);
//	freopen("bag.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>s;
		for(int i=0;i<n;i++){
			if(s[i]=='<')nfl[(i+1)%n]=1;
			else if(s[i]=='>')fl[i]=1;
			else fl[i]=nfl[(i+1)%n]=1;
		}
		int nifl=2;
		for(int i=0;i<n;i++){
			if(!fl[i]){
				nifl--;break;
			}
		}
		for(int i=0;i<n;i++){
			if(!nfl[i]){
				nifl--;break;
			}
		}
		if(nifl)printf("%lld\n",n);
		else{
			for(int i=0;i<n;i++){
				if(s[i]=='-')ans[i]=ans[(i+1)%n]=1;
			}aans=0;
			for(int i=0;i<n;i++)if(ans[i])aans++;
			printf("%lld\n",aans);
		}
		for(int i=0;i<n;i++)fl[i]=nfl[i]=ans[i]=0;
	}
	return 0;
}
/*

*/