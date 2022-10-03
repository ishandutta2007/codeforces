#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
#define kill(x) return cout<<x<<'\n', 0;

const int MAXN = 100010;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN];
int ans[MAXN];
map<int, int> mp;
queue<int> q;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>a>>b;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		q.push(mp[A[i]]=i);
	}
	while (!q.empty()){
		int i=q.front();
		q.pop();
		if (!mp.count(A[i])) continue ;
		bool f1=mp.count(a-A[i]), f2=mp.count(b-A[i]);
		if (!f1 && !f2) kill("NO")
		if (f1 && f2) continue ;
		if (f1){
			mp.erase(A[i]);
			mp.erase(a-A[i]);
			if (mp.count(b-(a-A[i]))) q.push(mp[b-(a-A[i])]);
		}
		if (f2){
			ans[i]=ans[mp[b-A[i]]]=1;
			mp.erase(A[i]);
			mp.erase(b-A[i]);
			if (mp.count(a-(b-A[i]))) q.push(mp[a-(b-A[i])]);
		}
	}
	
	cout<<"YES\n";
	for (int i=1; i<=n; i++) cout<<ans[i]<<' ';
	
	return 0;
}