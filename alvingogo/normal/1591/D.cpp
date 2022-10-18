#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

struct BIT{
	int n;
	vector<int> bt;
	void init(int x){
		n=x;
		bt.resize(n+1);
	}
	void update(int x){
		for(;x<=n;x+=(x&-x)){
			bt[x]++;
		}
	}
	int query(int x){
		int ans=0;
		for(;x>0;x-=(x&-x)){
			ans+=bt[x];
		}
		return ans;
	}
};
int main(){
	AquA;
	int t;
	cin >> t;
	while(t--){
		BIT bt;
		int n;
		cin >> n;
		bt.init(n);
		vector<int> v(n);
		vector<int> vis(n+1);
		long long ans=0;
		int flag=0;
		for(int i=0;i<n;i++){
			cin >> v[i];
			ans+=i-bt.query(v[i]);
			bt.update(v[i]);
			if(vis[v[i]]){
				flag=1;
			}
			vis[v[i]]++;
		}
		if(ans%2==0 || flag){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}