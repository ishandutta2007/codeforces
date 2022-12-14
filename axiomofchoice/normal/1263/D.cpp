#include <bits/stdc++.h>
using namespace std;
using ll=long long; //using lll=__int128;
using pii=pair<int,int>;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define N 200010
#define inf 1e9
#define qwq {cout<<"qwq"<<endl;}
#define int ll
const int mod=1000000007;
int n;
struct DSU{//d[x]=d[y]d[x]==d[y]
	int a[N],sz[N];
	void init(){
		repeat(i,0,n+1)a[i]=i,sz[i]=1;
	}
	int fa(int x){
		return a[x]==x?x:a[x]=fa(a[x]);
	}
	int& operator[](int x){
		return a[fa(x)];
	}
	void join(int x,int y){
		x=fa(x),y=fa(y);
		a[x]=y;
	}
}d;
string s;
int a[N][26];
set<int> Set;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	d.init();
	repeat(i,0,n){
		cin>>s;
		repeat(j,0,s.length())
			a[i][s[j]-'a']=1;
	}
	repeat(j,0,26){
		int p=-1;
		repeat(i,0,n)
		if(a[i][j]){
			if(p==-1)p=i;
			else d.join(p,i);
		}
	}
	int ans=0;
	repeat(i,0,n)
		Set.insert(d[i]);
	//repeat(i,0,n)
	//	cout<<(d[i])<<endl;
	cout<<Set.size()<<endl;
	return 0;
}