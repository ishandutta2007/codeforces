#include <iostream>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);
using namespace std;

int main(){
	int t;
	cin >> t;
	int v[1005]={0},x=0;
	for(int i=1;i<2000;i++){
		if(i%3==0 || i%10==3){
			continue;
		}
		v[x]=i;
		x++;
		if(x>=1000){
			break;
		}
	}
	while(t--){
		int a;
		cin >> a;
		cout << v[(a-1)] << endl;
		
	}
	return 0;
}