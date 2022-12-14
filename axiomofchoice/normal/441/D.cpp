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
const int N=3010;
const int inf=1e9;
const int mod=1e9+7;
//#define int ll
struct DSU{ //d[x]=d[y]d[x]==d[y]
	int a[N];
	void init(){
		repeat(i,0,N)a[i]=i;
	}
	int fa(int x){
		return a[x]==x?x:a[x]=fa(a[x]);
	}
	int& operator[](int x){
		return a[fa(x)];
	}
}d;
int a[N],p[N];
int n,m,cnt=0;
vector<pii> ans;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	repeat(i,1,n+1)cin>>a[i];
	cin>>m;
	vector<int> b;
	
	repeat(i,1,n+1)
	while(i!=a[i]){
		b=vector<int>(a,a+n+1);
		d.init();
		repeat(i,1,n+1)
		while(i!=b[i]){
			d[i]=d[b[i]];
			swap(b[i],b[b[i]]);
		}
		int j=i+1;
		while(d[i]!=d[j])j++;
		ans.push_back({i,j});
		swap(a[i],a[j]);
	}
	if(ans.size()>=m){
		cout<<ans.size()-m<<endl;
		repeat(i,0,ans.size()-m)
			cout<<ans[i].first<<' '<<ans[i].second<<' ';
	}
	else{
		d.init();
		for(auto i:ans)
			d[i.first]=d[i.second];
		int t=m-ans.size();
		ans.clear();
		repeat(i,1,n+1){
			if(t==0)break;
			if(d[1]!=d[i]){
				ans.push_back({1,i});
				d[1]=d[i];
				t--;
			}
		}
		cout<<ans.size()<<endl;
		repeat(i,0,ans.size())
			cout<<ans[i].first<<' '<<ans[i].second<<' ';
	}
	return 0;
}