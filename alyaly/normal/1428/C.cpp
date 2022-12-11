#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,fl[300001],aans;
string s;
signed main(){
//	freopen("bag2.in","r",stdin);
//	freopen("bag.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>s;
		n=s.size();int np=0;aans=0;
		for(int i=n-1;i>=0;i--){
			if(s[i]=='B')np++;
			else if(s[i]=='A'){
				if(np>0)np--;
				else aans++;
			}
		}cout<<aans+(np%2)<<endl;
	}
	return 0;
}
/*

*/