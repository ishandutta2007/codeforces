#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define N 200010
#define mod 1000000007
//#define int ll
#define inf mod
tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> t;//

pii a[N];
int n,m,k,pos,x;
struct node{
	int k,pos,p;
	bool operator<(node b)const{
		return k<b.k;
	}
};
multiset<node> query;
vector<pii> ans;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	repeat(i,0,n)cin>>x,a[i]={-x,i};
	sort(a,a+n);
	cin>>m;
	repeat(i,0,m){
		cin>>k>>pos;
		query.insert((node){k,pos,i});
	}
	int p=0;
	for(auto i:query){
		//cout<<"query:"<<i.k<<' '<<i.pos<<' '<<i.p<<endl;
		while(p<i.k)t.insert({a[p].second,a[p].first}),p++;
		ans.push_back({i.p,-t.find_by_order(i.pos-1)->second});
		//repeat(s,0,p)
		//	cout<<-t.find_by_order(s)->first<<' ';
		//cout<<endl;
	}
	sort(ans.begin(),ans.end());
	repeat(i,0,ans.size()){
		cout<<ans[i].second<<endl;
	}
	return 0;
}