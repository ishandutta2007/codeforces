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
		int a=0,b=0;
		for(int i=0;i<n;i++){
			cin >> v[i];
			if(v[i]==1){
				a++;
			}
			else if(v[i]==0){
				b++;
			}
		}
		cout << 1ll*a*(1ll<<b) << "\n";
	}
	return 0;
}