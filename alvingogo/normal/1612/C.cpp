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
		long long k;
		long long x;
		cin >> k >> x;
		if(k*k<=x){
			cout << 2*k-1 << "\n";
			continue;
		}
		if((k*(k+1)/2)>=x){
			long long l=1,r=k;
			while(r>l){
				long long m=(l+r)/2;
				if((m*(m+1)/2>=x)){
					r=m;
				}
				else{
					l=m+1;
				}
			}
			cout << l << "\n";
		}
		else{
			x-=(k*(k+1)/2);
			long long l=1,r=k;
			while(r>l){
				long long m=(l+r)/2;
				if((k+k-m-1)*m/2>=x){
					r=m;
				}
				else{
					l=m+1;
				}
			}
			cout << k+l << "\n";
		}
	}
	return 0;
}