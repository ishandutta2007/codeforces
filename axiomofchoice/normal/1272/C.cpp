#include <bits/stdc++.h>
using namespace std;
using ll=long long; //using lll=__int128;
using pii=pair<int,int>;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=1010;
const int inf=1e9;
const int mod=1000000007;
#define int ll
char c;
int cnt[256];
int n,k,now,pre,ans=0;
string s;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	cin>>s;
	repeat(i,0,k)cin>>c,cnt[c]=1;
	pre=0;
	repeat(i,0,n)
	if(cnt[s[i]]){
		now=pre+1;
		ans+=now;
		pre=now;
	}
	else pre=0;
	cout<<ans<<endl;
	return 0;
}