#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=400010;
const int inf=1e9;
const int mod=1000000007;
//#define int ll
map<int,int> Map;
multiset<int> Set;
int a[N],n,back[N],s[N];
pii f[N];
vector< vector<int> > A;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	int cnt=0;
	repeat(i,0,n){
		cin>>a[i];
		if(!Map.count(a[i])){
			Map[a[i]]=++cnt;
			back[cnt]=a[i];
		}
		a[i]=Map[a[i]];
		f[a[i]].second=a[i];
		f[a[i]].first++;
	}
	Map=map<int,int>();
	sort(f,f+n+1,greater<pii>());
	s[0]=f[0].first;
	repeat(i,1,n+1)s[i]=f[i].first,s[i]+=s[i-1];
	int p=0,ans=0,ansp,ansi;
	//repeat(i,0,n+1)cout<<f[i].first<<endl;
	repeat_back(i,1,n+1){
		while(f[p].first>i)p++;
		int sum;
		if(p==0)sum=n;else sum=p*i+n-s[p-1];
		if((sum/i)<i)continue;//cout<<i<<' '<<p<<' '<<sum<<endl;
		if((sum/i)*i>ans){
			ans=(sum/i)*i;
			ansp=p;
			ansi=i;
		}
	}//return 0;
	int i=ansi; p=ansp;
	int j=ans/i;
	int x=0,y=0;
	A.resize(i);
	repeat(ii,0,i)A[ii].resize(j);
	int pi=0,ti=0,xypi=0,xyti=0;
	repeat(iii,0,ans){//cout<<x<<' '<<y<<endl;
		A[x][y]=back[f[pi].second];
		x++,y=(y+1)%j;
		xyti++;if(xyti==i){xyti=x=0;y=++xypi;}
		ti++;
		if(ti==min(i,f[pi].first)){
			pi++;
			ti=0;
		}
	}
	cout<<ans<<endl;
	cout<<i<<' '<<j<<endl;
	repeat(ii,0,i)
	repeat(jj,0,j)
		cout<<A[ii][jj]<<" \n"[jj==j-1];
    return 0;
}