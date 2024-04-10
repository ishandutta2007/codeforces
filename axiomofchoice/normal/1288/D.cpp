#include <bits/stdc++.h>
using namespace std;
#define lll __int128
typedef long long ll;
typedef pair<int,int> pii;
typedef double lf; const lf err=1e-7;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
#define orz(x) {cout<<#x": "<<x<<endl;}
const int N=10010;
const int inf=1e9+10;
const int mod=1e9+7;
//#define int ll
int n,m,a[N],s[N],p[N],tans=-inf,tans1;
void solve(){
	cin>>n>>m; int MM=1<<m;
	repeat(t,0,MM)a[t]=-inf;
	repeat(i,0,n){
		repeat(j,0,m)
			cin>>s[j];
		if(m==1 && tans<s[0])tans=s[0],tans1=i+1;
		repeat(t,0,MM){
			int r=inf;
			repeat(j,0,m)
			if((t>>j)&1){
				r=min(r,s[j]);
			}
			if(r>a[t]){
				a[t]=r;
				p[t]=i+1;
			}
		}
		//if(i==1)cout<<a[0b10100]<<endl;
	}
	//cout<<a[0b1]<<endl;
	int ans=-inf,ans1,ans2;
	repeat(t,1,MM-1){
		int s=(MM-1)^t;
		if(min(a[t],a[s])>ans){
			ans=min(a[t],a[s]);
			ans1=p[t];
			ans2=p[s];
			//cout<<t<<endl;
		}
	}
	if(m==1)cout<<tans1<<' '<<tans1<<endl;
	else cout<<ans1<<' '<<ans2<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//int T; cin>>T;
	//while(T--)
	solve();
	return 0;
}