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
		int n;
		long long h;
		cin >> n >> h;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
		}
		long long l=1,r=h;
		while(r>l){
			long long m=(r+l)/2;
			long long ax=0,sum=0;
			for(int i=0;i<n;i++){
				if(v[i]>ax){
					sum+=m;
				}
				else{
					sum+=m+v[i]-ax;
				}
				ax=v[i]+m;
			}
			if(sum>=h){
				r=m;
			}
			else{
				l=m+1;
			}
		}
		cout << l << "\n";
	}
	return 0;
}