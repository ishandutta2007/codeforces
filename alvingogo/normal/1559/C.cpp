#include <iostream>
#include <vector>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);cout.tie(0);
using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
		}
		if(v[0]==1){
			cout << n+1 << " ";
			for(int i=1;i<=n;i++){
				cout << i;
				if(i!=n){
					cout << " ";
				}
			}
			cout << "\n";
			continue;
		}
		else if(v[n-1]==0){
			for(int i=1;i<=n;i++){
				cout << i << " ";
			}
			cout << n+1;
			cout << "\n";
			continue;
		}
		int p=0;
		for(int i=0;i<n-1;i++){
			if(v[i]==0 && v[i+1]==1){
				p=i+1;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			cout << i;
			if(i==p){
				cout << " " << n+1;
			}
			if(i!=n){
				cout << " ";
			}
		}
		cout << "\n";
	}
		
	return 0;
}