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
		int n,a,b;
		cin >> n >> a >> b;
		if(a-b>1 || b-a>1){
			cout << -1 << "\n";
			continue;
		}
		if(a+b>n-2){
			cout << -1 << "\n";
			continue;
		}
		if(a<=b){
			cout << n << " ";
			int x=0,y=n-1;
			for(int i=1;i<=a+b;i++){
				if(i%2){
					cout << i/2+1 << " ";
					x=i/2+1;
				}
				else{
					cout << n-i/2 << " ";
					y=n-i/2-1;
				}
			}
			if((a+b)%2){
				while(x<y){
					x++;
					cout << x << " ";
				}
			}
			else{
				while(y>x){
					cout << y << " ";
					y--;
				}
			}
			cout << "\n";
		}
		else{
			cout << 1 << " ";
			int x=1,y=n;
			for(int i=1;i<=a+b;i++){
				if(i%2==0){
					cout << i/2+1 << " ";
					x=i/2+1;
				}
				else{
					cout << n-i/2 << " ";
					y=n-i/2-1;
				}
			}
			if((a+b)%2==0){
				while(x<y){
					x++;
					cout << x << " ";
				}
			}
			else{
				while(y>x){
					cout << y << " ";
					y--;
				}
			}
			cout << "\n";
		}
		
	}
	return 0;
}