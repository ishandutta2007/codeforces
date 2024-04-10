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
#define orzeach(a) cerr<<#a": "; for(auto I:a)cerr<<i<<" "; cerr<<endl;
#define fi first
#define se second
ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;}
mt19937 rnd(time(0));
//tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> t; //
const int N=100010;
const int mod=(1?1000000007:998244353);
//#define int ll
string s,t;
int rec[26][N];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>s>>t;
		repeat(i,0,26)
		repeat(j,0,s.size())
			rec[i][j]=-1;
		int m=s.size();
		repeat(i,0,26){
			int p=-1;
			repeat(j,0,s.size()){
				if(s[j]==i+'a'){
					p=j;
					rec[i][j]=0;
				}
			}
			int dis=0;
			if(p!=-1)
			repeat(j,1,(int)s.size()+1){
				if(rec[i][(p-j+m)%m]==0){
					rec[i][(p-j+m)%m]=++dis;
					dis=0;
				}
				else rec[i][(p-j+m)%m]=++dis;
			}
		}
		/*repeat(i,0,26){
			repeat(j,0,m)
				cout<<rec[i][j]<<' ';
			cout<<endl;
		}*/
		int n=t.size(),p=m-1,ans=0;
		repeat(i,0,n){
			int d=rec[t[i]-'a'][p];
			if(d==-1){ans=-1;break;}
			p+=d;
			if(p>=m){
				ans++;
				p-=m;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}