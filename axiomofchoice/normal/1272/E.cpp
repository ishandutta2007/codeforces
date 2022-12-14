#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=200010;
const int inf=1e9;
const int mod=1000000007;
//#define int ll
int ans[N],a[N],n;
bool vis[N];
vector<int> edge[N];
priority_queue<pii> q;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	repeat(i,0,n){
		cin>>a[i];
		//a[i]%=2;
		ans[i]=-1;
		if(i+a[i]<n)edge[i+a[i]].push_back(i);
		if(i-a[i]>=0)edge[i-a[i]].push_back(i);
	}
	repeat(x,0,n){
		if(x+a[x]<n && (a[x]^a[x+a[x]])%2==1
		|| x-a[x]>=0 && (a[x]^a[x-a[x]])%2==1)
			ans[x]=1,q.push({-1,x});
	}
	//repeat(i,0,n)cout<<ans[i]<<' ';cout<<endl;
	while(!q.empty()){
		int x=q.top().second; q.pop();
		for(auto p:edge[x])
		if(ans[p]==-1){
			ans[p]=ans[x]+1;
			q.push({-ans[p],p});
		}
	}
	repeat(i,0,n)cout<<ans[i]<<' ';
	cout<<endl;
    return 0;
}
/*
7
1 0 0 3 0 0 3
*/