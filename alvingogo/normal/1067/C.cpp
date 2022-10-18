#include <bits/stdc++.h>
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int main(){
	AquA;
	int n;
	cin >> n;
	for(int i=0;i<n/2;i++){
		cout << i-n/4 << " " << 0 << "\n";
	}
	for(int j=0;j<n-n/2;j++){
		if(j-n/4==0){
			cout << n/2-n/4 << " " << 0 << "\n";
		}
		else{
			cout << 0 << " " << j-n/4 << "\n";
		}
	}
	return 0;
}