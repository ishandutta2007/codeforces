#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int calc(vector<int> v){
	int n=v.size();
	vector<int> dp(n);
	dp[0]=1+(v[0]==0);
	
	for(int i=1;i<n;i++){
		int z=0;
		map<int,int> m;
		m[v[i]]++;
		while(m.find(z)!=m.end()){
			z++;
		}
		for(int j=i-1;j>=0;j--){
			dp[i]=max(dp[i],dp[j]+z+1);
			m[v[j]]++;
			while(m.find(z)!=m.end()){
				z++;
			}
		}
	}
	return dp[n-1];
}
int main(){
	AquA;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
		}
		long long ans=0;
		for(int l=0;l<n;l++){
			for(int r=l;r<n;r++){
				vector<int> x;
				for(int i=l;i<=r;i++){
					x.push_back(v[i]);
				}
				int h=calc(x);
				ans+=h;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}