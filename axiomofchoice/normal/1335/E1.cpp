#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
//#define int ll
int a[N],s[201][N];
signed main(){
	int T=read();
	while(T--){
		int n=read();
		repeat(i,1,n+1)a[i]=read();
		repeat(c,1,200+1)
			s[c][n+1]=0;
		repeat(c,1,200+1)
		repeat_back(i,1,n+1)
			s[c][i]=s[c][i+1]+(a[i]==c);
		int ans=1;
		repeat(i,1,n+1){
			int c=a[i];
			int pre=s[c][1]-s[c][i+1];
			int p2=upper_bound(s[c]+1,s[c]+n+1,pre,greater<int>())-s[c]-1;
			
			//cout<<i<<' '<<c<<' '<<pre<<' '<<p2<<endl;
			if(p2>i)
			repeat(c2,1,200+1)
				ans=max(ans,s[c2][i+1]-s[c2][p2]+2*pre);//,s[c2][i+1]-s[c2][p2]>0?cout<<c2<<' '<<s[c2][i+1]-s[c2][p2]+2*pre<<endl:cout;
		}
		cout<<ans<<endl;
	}
	return 0;
}