#include <bits/stdc++.h>
using namespace std;
#define lll __int128
typedef long long ll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=200010;
const int inf=1e9;
const int mod=1e9+7;
//#define int ll
int a[N],f[N];
int n;
vector<pii> ans;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	repeat(i,0,n-1)cin>>a[i];
	f[a[0]]=1;
	int top=n;
	repeat(i,0,n-1){
		while(f[top])top--;
		if(f[a[i]]){
			ans.push_back({top,a[i]});
			f[top]=1;
		}
		else{
			ans.push_back({a[i],ans.back().first});
			ans[ans.size()-2].first=a[i];
			swap(ans.back().first,ans.back().second);
			f[a[i]]=1;
		}
	}
	cout<<a[0]<<endl;
	repeat(i,0,n-1){
		cout<<ans[i].first<<' '<<ans[i].second<<endl;
	}
	return 0;
}