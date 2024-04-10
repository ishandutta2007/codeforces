#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);cout.tie(0);
using namespace std;
 
long long inf=10000000000000;
int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n);
		double s=0,m=-inf;
		for(int i=0;i<n;i++){
			cin >> v[i];
			s+=v[i];
			if(v[i]>m){
				m=v[i];
			}
		}
		cout << fixed << setprecision(9) << double(m)+double(s-m)/double(n-1) << endl;		
	}
	return 0;
}