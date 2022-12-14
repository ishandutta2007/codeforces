#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2;
#define int ll
int n,a[N],ans[N];
vector<int> rec;
signed main(){
	cin>>n;
	repeat(i,0,n)cin>>a[i];
	int low=0;
	repeat(i,0,n){
		rec.push_back(i);
		repeat(j,low,a[i]){
			if(rec.empty())cout<<-1<<endl,exit(0);
			ans[rec.back()]=j,rec.pop_back();
		}
		low=a[i];
	}
	while(!rec.empty())ans[rec.back()]=1e6,rec.pop_back();
	repeat(i,0,n)cout<<ans[i]<<' ';
	return 0;
}