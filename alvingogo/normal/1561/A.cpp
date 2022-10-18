#include <iostream>
#include <vector>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		int x=0;
		while(1){
			int flag=0;
			for(int i=0;i<n;i++){
				if(a[i]!=i+1){
					flag=1;
					break;
				}
			}
			if(flag==0){
				break;
			}
			for(int i=x%2;i<n-1;i+=2){
				if(a[i]>a[i+1]){
					swap(a[i],a[i+1]);
				}
			}
			x++;
		}
		cout << x << "\n";
	}
	return 0;
}