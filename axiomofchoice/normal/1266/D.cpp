#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
#define pb push_back
const int N=100010;
const int inf=1e9;
const int mod=1000000007;
#define int ll
struct node{
	int deg,p;
	bool operator<(node b)const{
		return deg>b.deg;
	}
}a[N];
int n,m;
vector<int> x,y,z;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	repeat(i,0,n)a[i].p=i;
	repeat(i,0,m){
		int x,y,w;
		cin>>x>>y>>w; x--,y--;
		a[x].deg+=w;
		a[y].deg-=w;
	}
	sort(a,a+n);
	int l=0,r=n-1;
	while(l<r){
		if(a[l].deg==0)break;
		int m=min(a[l].deg,-a[r].deg);
		x.pb(a[l].p);
		y.pb(a[r].p);
		z.pb(m);
		a[l].deg-=m; if(a[l].deg==0)l++;
		a[r].deg+=m; if(a[r].deg==0)r--;
	}
	cout<<x.size()<<endl;
	repeat(i,0,x.size())
		cout<<x[i]+1<<' '<<y[i]+1<<' '<<z[i]<<endl;
    return 0;
}