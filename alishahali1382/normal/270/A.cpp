#include <iostream>

using namespace std;

int main(){
	int n,theta;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>
		theta;
		theta=180-theta;
		if (360%theta==0){
			cout<<"YES";
		}
		else{
			cout<<"NO";
		}
		cout<<endl;
	}
}