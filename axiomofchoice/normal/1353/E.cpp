#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,a0) memset(a,a0,sizeof(a))
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=1000010; typedef long long ll; const int inf=~0u>>2; typedef pair<int,int> pii;
#define int ll
int T,n,k;
string S;
vector<int> a,s;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>k>>S;
		ll ans=1e9,sum=0;
		repeat(i,0,n)sum+=S[i]=='1';
		repeat(i,0,k){
			a.clear();
			for(int j=i;j<n;j+=k)
				a.push_back((S[j]-'0')*2-1);
			int r=0,tans=0,now=0;
			while(r<(int)a.size()){
				now+=a[r++];
				if(now<0)now=0;
				tans=max(tans,now);
			}
			ans=min(ans,sum-tans);
		}
		cout<<ans<<endl;
	}
	return 0;
}