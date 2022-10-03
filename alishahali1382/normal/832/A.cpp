#include <iostream>

using namespace std;

main(){
	long long int n,k;
	cin>>n>>k;
	string out="NO";
	if ((n%(2*k))>=k){
		out="YES";
	}
	cout<<out<<endl;
}