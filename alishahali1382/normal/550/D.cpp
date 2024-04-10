#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int k;

int main(){
	//freopen("input.txt", "r", stdin);
	cin>>k;
	if (k==1){
		cout<<"YES\n2 1\n1 2"<<endl;
		return 0;
	}
	if (!(k%2)){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	cout<<2*k+4<<' '<<((2*k+4)*k)/2<<endl;
	
	for (int i=2; i<=k; i++){
		cout<<"1 "<<i<<endl;
	}
	for (int i=2; i<=k; i++){
		for (int j=i+1+(i+1)%2; j<=k; j++){
			cout<<i<<' '<<j<<endl;
		}
		cout<<i<<' '<<k+1<<endl;
		cout<<i<<' '<<k+2<<endl;
	}
	cout<<k+1<<' '<<k+2<<endl;
	
	
	
	
	for (int i=2; i<=k; i++){
		cout<<k+3<<' '<<i+k+2<<endl;
	}
	for (int i=2; i<=k; i++){
		for (int j=i+1+(i+1)%2; j<=k; j++){
			cout<<i+k+2<<' '<<j+k+2<<endl;
		}
		cout<<i+k+2<<' '<<2*k+3<<endl;
		cout<<i+k+2<<' '<<2*k+4<<endl;
	}
	cout<<2*k+3<<' '<<2*k+4<<endl;
	
	
	cout<<1<<' '<<k+3<<endl;
	
	return 0;
}