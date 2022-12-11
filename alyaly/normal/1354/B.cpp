#include<bits/stdc++.h>
//#pragma GCC optimize(2)
#define int long long
#include<queue>
//#define P 998244353
using namespace std;
int T,ans,pa,pb,g[257];
string s;
signed main(){
	cin>>T;
	while(T--){
		cin>>s;
		pa=pb=1;
		ans=999999;
		g[s[0]-'0']=1;
		for(pa=1;pa<=s.size();pa++){
			while((!g[3]||!g[1]||!g[2])&&pb<=s.size()){
				pb++;
				if(pb>s.size()){
					pb--;
					break;
				}
				g[s[pb-1]-'0']++;
			}
			if(g[1]&&g[2]&&g[3]){
				ans=min(ans,pb-pa+1);
			}
			
			g[s[pa-1]-'0']--;
		}
		if(ans!=999999) printf("%d\n",ans);
		else printf("0\n");
	}
	return 0;
}
/*

*/