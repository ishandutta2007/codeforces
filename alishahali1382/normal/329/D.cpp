#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, x;

int main(){
	//freopen("input.txt", "r", stdin);
	cin>>n>>x;
	char out[100][100];
	memset(out, '.', sizeof(out)); // false ==> '.'
	if (n==5){
		cout<<">...v\nv.<..\n..^..\n>....\n..^.<\n1 1"<<endl;
		return 0;
	}
	if (n==3){
		cout<<">vv\n^<.\n^.<\n1 3"<<endl;
		return 0;
	}
	
	cout<<"v<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	cout<<"v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v^"<<endl;
	for (int i=0; i<24; i++){
		cout<<"v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v."<<endl;
		cout<<"v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^"<<endl;
	}
	for (int i=0; i<24; i++){
		cout<<"v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^"<<endl;
		cout<<".^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^"<<endl;
	}
	cout<<">^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^"<<endl;
	for (int i=0; i<100; i++){
		cout<<'.';
	}
	cout<<endl;
	
	cout<<"1 1"<<endl;
	 
	
	
	

	return 0;
}