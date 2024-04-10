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
		int h=1;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
		}
		for(int i=0;i<n;i++){
			if(i){
				if(v[i]){
					if(v[i-1]){
						h+=5;
					}
					else{
						h++;
					}
				}
				else if(v[i-1]==0){
					h=-1;
					break;
				}
				
			}
			else{
				if(v[i]){
					h++;
				}
			}
		}
		cout << h << "\n";
	}
	return 0;
}