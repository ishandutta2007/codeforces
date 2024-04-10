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
		int n,m;
		cin >> n >> m;
		vector<int> v(n);
		int a,b,c;
		for(int i=0;i<m;i++){
			cin >> a >> b >> c;
			v[b-1]=1;
		}
		for(int i=0;i<n;i++){
			if(v[i]==0){
				for(int j=0;j<n;j++){
					if(i==j){
						continue;
					}
					cout << i+1 << " " << j+1 << "\n";
				}
				break;
			}
		}
	}
	return 0;
}