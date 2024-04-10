#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
		cin >> n;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		int maxx=0;
		for(int i=1;i<n-1;i++){
			if(a[i]>a[i-1] && a[i]>a[i+1]){
				maxx++;
				a[i+1]=max(a[i],a[min(n-1,i+2)]);
			}
		}
		cout << maxx << "\n";
		for(int i=0;i<n;i++){
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}