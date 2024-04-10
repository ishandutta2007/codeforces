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
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
		}
		for(int i=2;i<=10000;i++){
			for(int j=0;j<n;j++){
				if(v[j]%i!=0){
					break;
				}
				if(j==n-1){
					for(int k=0;k<n;k++){
						v[k]/=i;
					}
				}
			}	
		}
		int h=0;
		int flag=0;
		for(int i=0;i<n-1;i++){
			if(h*v[i]>0){
				flag=0;
				h-=v[i];
			}
			else{
				flag=1;
				h+=v[i];
			}
			if(h==0 && i==n-2){
				if(flag==0){
					h-=v[i];
				}
				else{
					h+=v[i];
				}
				flag=1;
			}
			else{
				flag=0;
			}
		}
		int k=0;
		for(int i=0;i<n-1;i++){
			if(k*v[i]>0){
				k-=v[i];
				if(flag==1 && i==n-2){
					cout << -2*v[n-1] << " ";
				}
				else{
					cout << -v[n-1] << " ";
				}
			}
			else{
				k+=v[i];
				if(flag==1 && i==n-2){
					cout << 2*v[n-1] << " ";
				}
				else{
					cout << v[n-1] << " ";
				}
			}	
		}
		cout << -h << "\n";
	}
	return 0;
}