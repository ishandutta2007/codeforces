#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);cout.tie(0);
using namespace std;

long long inf=10000000000;
int main(){
	//fastio;
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int> v(n),x(n),z(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
			x[i]=v[i];
		}
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		for(int i=0;i<n;i++){
			x[i]=lower_bound(v.begin(),v.end(),x[i])-v.begin();
			z[x[i]]=i;
			
		}
		int kx=1;
		for(int i=1;i<n;i++){
			if(z[i]-z[i-1]!=1){
				kx++;
			}
		}
		if(kx<=k){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}