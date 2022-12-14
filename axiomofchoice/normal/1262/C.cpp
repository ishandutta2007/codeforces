#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define N 100010
#define mod 1000000007
#define int ll
#define inf mod
int T,n,k;
string s,t;
vector<pii> ans;
void reverse(int l,int r){
	repeat(i,l,r+1)
	if(i<l+r-i)
		swap(s[i],s[l+r-i]);
	ans.push_back({l,r});
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		ans.clear();
		cin>>n>>k;
		t="";
		repeat(i,0,k-1)t+="()";
		repeat(i,0,n/2-k+1)t+='(';
		repeat(i,0,n/2-k+1)t+=')';
		//cout<<t<<endl;
		cin>>s;
		repeat(i,0,n){
			if(s[i]!=t[i])
			repeat(j,i,n)
			if(s[j]==t[i]){
				reverse(i,j);
				break;
			}
		}
		//cout<<s<<endl;
		cout<<ans.size()<<endl;
		repeat(i,0,ans.size())
			cout<<ans[i].first+1<<' '<<ans[i].second+1<<endl;
	}
	return 0;
}