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
const int inf=2e9;
const int mod=1000000007;
#define int ll
int n,q,x,s,y,ans=0;
struct node{
	int x,s,y;
	node(){}
	node(int x,int s,int y):x(x),s(s),y(y){}
	bool operator<(node b)const{
		return make_tuple(x,s,y)<make_tuple(b.x,b.s,b.y);
	}
};
set<node> Set;
int a[N],cnt[N];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	repeat(i,0,n)cin>>a[i],ans+=a[i];
	cin>>q;
	Set.insert(node(inf,0,0));
	while(q--){
		cin>>x>>s>>y; x--,y--;
		auto p=Set.lower_bound(node(x,s,0));
		if(p->x==x && p->s==s){
			cnt[p->y]--;
			if(cnt[p->y]<a[p->y])
				ans++;
			Set.erase(p);
		}
		if(y!=-1){
			Set.insert(node(x,s,y));
			if(cnt[y]<a[y])ans--;
			cnt[y]++;
		}
		cout<<ans<<endl;
	}
    return 0;
}