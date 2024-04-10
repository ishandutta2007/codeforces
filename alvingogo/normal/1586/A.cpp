#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n);
		int sum=0;
		int k=0;
		for(int i=0;i<n;i++){
			cin >> v[i];
			sum+=v[i];
			if(v[i]%2==1){
				k=i+1;	
			}
		}
		int f=0;
		for(int i=2;i*i<=sum;i++){
			if(sum%i==0){
				f=1;
				break;
			}
		}
		if(f==1){
			cout << n << "\n";
			for(int i=1;i<=n;i++){
				cout << i << " ";
			}
			cout << "\n";
		}
		else{
			cout << n-1 << "\n";
			for(int i=1;i<=n;i++){
				if(i==k){
					continue;
				}
				cout << i << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}