# include<iostream>
# include<string>
# include<vector>

using namespace std;

int main(){
	int n ,k;
	cin>> n >> k;
	while (1){
	for (int i=1; i<n+1; i++){
		if(k >= i){
			k -= i;
		}
		else{
			cout << k;
			return 0;
		}
	}
}
	cout << 0;
	return 0;
}