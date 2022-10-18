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
		int x,y;
		cin >> x >> y;
		int d=abs(x)+abs(y);
		int a=-51,b=-51;
		for(int i=-50;i<=50;i++){
			for(int j=-50;j<=50;j++){
				if(2*(abs(i)+abs(j))==d && 2*(abs(i-x)+abs(j-y))==d){
					a=i;
					b=j;
				}
			}
		}
		if(a==-51){
			cout << "-1 -1\n";
		}
		else{
			cout << a << " " << b << "\n";
		}
	}
	return 0;
}