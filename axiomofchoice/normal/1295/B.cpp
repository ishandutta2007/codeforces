#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define lll __int128
typedef long long ll; const int inf=2e9;
typedef double lf; const lf err=1e-11; typedef long double llf;
typedef pair<int,int> pii;
#define repeat(i,a,b) for(int i=(a),__=(b);i<__;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,__=(a);i>=__;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq (cerr<<"qwq"<<endl)
#define orz(x) (cerr<<#x": "<<x<<endl)
#define orzarr(a,n) cerr<<#a": "; repeat(I,0,n)cerr<<(a)[I]<<" "; cerr<<endl;
#define orzeach(a) cerr<<#a": "; for(auto i:a)cerr<<i<<" "; cerr<<endl;
#define fi first
#define se second
ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;}
mt19937 rnd(time(0));
//tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> t; //
const int N=100010;
const int mod=(1?1000000007:998244353);
//#define int ll
int cnt_[2*N]; auto cnt=cnt_+N;
int sum_[N]; auto sum=sum_+1;
int n,x;
string s;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin>>t;
	while(t--){
		cin>>n>>x;
		cin>>s;
		if(x<0)
			repeat(i,0,n)s[i]='0'+'1'-s[i];
		x=abs(x);
		repeat(i,0,n){
			sum[i]=sum[i-1]+int(s[i]=='0')*2-1;
			cnt[sum[i-1]]++;
		}
		int tt=sum[n-1];
		if(x>=2*n+5 && tt>0)
			x-=((x-2*n-5)/tt-1)*tt;//orz(x);
		ll ans=0;
		//orz(sum[n-1]);
		for(int c=0;;c+=tt){
			if(abs(c-x)<n+5)ans+=cnt[x-c];
			if(tt==0){
				if(ans>0)ans=-1;
				break;
			}
			if(x-n-5>c && tt<0)break;
			if(c-n-5>x && tt>0)break;
		}
		repeat(i,-n-5,n+5)cnt[i]=0;
		cout<<ans<<endl;
	}
	return 0;
}