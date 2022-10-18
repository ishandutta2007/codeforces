#include <bits/stdc++.h>
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int main(){
	AquA;
	int t;
	cin >> t;
	while(t--){
		long long s,k,n;
		cin >> s >> n >> k;
		if(s<k){
			cout << "NO\n";
		}
		else if(s==k){
			cout << "YES\n";
		}
		else{
			long long u=s%k,v=(s-u)/k;
			if(v%2==1){
				if(2*n>=s+k-(u+1)){
					cout << "YES\n";
				}
				else{
					cout << "NO\n";
				}
			}
			else{
				if(2*n>=s+k-(k-u-1)){
					cout << "YES\n";
				}
				else{
					cout << "NO\n";
				}
			}
		}
	}
	return 0;
}