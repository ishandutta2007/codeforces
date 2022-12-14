#include <bits/stdc++.h>
using namespace std;
#define lll __int128
typedef long long ll; const int inf=2e9;
typedef double lf; const lf err=1e-7;
typedef pair<int,int> pii;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define Clear(a) {a=decltype(a)();}
#define qwq {cerr<<"qwq"<<endl;}
#define orz(x) {cerr<<#x": "<<x<<endl;}
ll read(){ll n; scanf("%lld",&n); return n;}
const int N=100010;
const int mod=1e9+7;
#define int ll
int n,q,tot=0;
int a[N][4],cnt[N][2];
void remove(int x,int y){
	int p=x%2;
	cnt[y][p]--;
	a[y][x]=0;
	if(cnt[y][p]==0 && cnt[y][p^1]>0)
		tot--;
}
void add(int x,int y){
	int p=x%2;
	cnt[y][p]++;
	a[y][x]=1;
	if(cnt[y][p]==1 && cnt[y][p^1]>0)tot++;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>q;
	while(q--){
		int x,y; cin>>x>>y; x--,y--;
		if(a[y][x]){
			remove(x,y);
			remove(x+2,y+1);
		}
		else{
			add(x,y);
			add(x+2,y+1);
		}
		if(tot)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
		//repeat(i,0,10){
		//	cout<<cnt[i][0]<<cnt[i][1]<<' ';
		//}
		//cout<<endl;
	}
	return 0;
}