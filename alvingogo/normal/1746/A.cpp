#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
	int t;
	cin >> t;
	while(t--){
		int k,n;
		cin >> n >> k;
		vector<int> v(n);
		int flag=0;
		for(int i=0;i<n;i++){
			cin >> v[i];
			if(v[i]==1){
				flag=1;
			}
		}
		if(flag){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
    return 0;
}