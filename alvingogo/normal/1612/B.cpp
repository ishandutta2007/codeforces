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
		int n,a,b;
		cin >> n >> a >> b;
		if(b<n/2 || a>n/2+1){
			cout << -1 << "\n";
			continue;
		}
		if((b==n/2 && a<=n/2) || (a==n/2+1 && b>n/2+1)){
			cout << -1 << "\n";
			continue;
		}
		set<int> s;
		for(int i=1;i<=n;i++){
			if(i!=a && i!=b){
				s.insert(-i);
			}
		}
		cout << a << " ";
		for(auto y:s){
			cout << -y << " ";
		}
		cout << b << "\n";
	}
	return 0;
}