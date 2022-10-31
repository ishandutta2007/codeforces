#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
int n,col[N],nn,a[5];
vector<int> g[N],vec[N],r[5];
il void dfs(ct x){
	r[col[x]].push_back(x),a[col[x]]+=x,a[col[x]]=(a[col[x]]>=nn?a[col[x]]-nn:a[col[x]]);
	for(const int &i : g[x]) 
		if(!col[i]) col[i]=col[x]^3,dfs(i);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n,nn=n<<1;
	if(!(n&1)){
		cout<<"First"<<endl,cout<<flush;
		for(it i=0;i<nn;++i) cout<<i%n+1<<' ';
		cout<<endl,cout<<flush;
		return 0;
	}
	cout<<"Second"<<endl;cout<<flush;
	for(it i=1,x;i<=nn;++i) cin>>x,vec[x].push_back(i);
	for(it i=1;i<=n;++i) g[vec[i][0]].push_back(vec[i][1]),g[vec[i][1]].push_back(vec[i][0]),g[i].push_back(i+n),g[i+n].push_back(i);
	for(it i=1;i<=nn;++i) if(!col[i]) col[i]=1,dfs(i);
	if(a[1]%nn==0) for(const int &i : r[1]) cout<<i<<' ';
	else for(const int &i : r[2]) cout<<i<<' ';
	cout<<endl,cout<<flush;
	return 0;
}