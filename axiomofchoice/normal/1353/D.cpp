#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,a0) memset(a,a0,sizeof(a))
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; typedef pair<int,int> pii;
//#define int ll
int T,n;
int ans[N];
struct op{
	bool operator()(const pii &x,const pii &y){
		return pii(x.second-x.first,-x.first)<pii(y.second-y.first,-y.first);
	}
};
priority_queue<pii,vector<pii>,op> q;
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		q.push({1,n});
		int dcnt=0;
		while(!q.empty()){
			int l=q.top().first,r=q.top().second; q.pop();
			int m=(l+r)/2;
			ans[m]=++dcnt;
			if(l<m)q.push({l,m-1});
			if(m<r)q.push({m+1,r});
		}
		repeat(i,1,n+1)cout<<ans[i]<<' ';
		cout<<endl;
	}
	return 0;
}