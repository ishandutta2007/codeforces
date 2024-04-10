#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	cin>>n;
	cout<<(n-3*(n%2))/2+n%2<<endl;
	if (n%2==0){
		for (int i=1;i*2<=n;i++){
			cout<<"2 ";
		}
		cout<<endl;
	}
	else{
		for (int i=0;i*2<n-3;i++){
			cout<<"2 ";
		}
		cout<<"3"<<endl;
	}
}