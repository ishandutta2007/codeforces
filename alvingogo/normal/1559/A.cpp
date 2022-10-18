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
		int x=0;
		for(int i=0;i<31;i++){
			int flag=0;
			for(int j=0;j<n;j++){
				if((v[j]&(1<<i))==0){
					flag=1;
					break;
				}
			}
			if(flag==0){
				x+=(1<<i);
			}
		}
		cout << x << "\n";
	}
	return 0;
}