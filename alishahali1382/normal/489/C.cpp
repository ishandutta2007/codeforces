#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int out[110];

int main(){
	int m,s;
	cin>>m>>s;
	if (m==1 && s==0){
		cout<<"0 0"<<endl;
		return 0;
	}
	if (s==0 || m==0 || m*9<s){
		cout<<-1<<' '<<-1<<endl;
		return 0;
	}
	int y=m-1, k=s/9;
	out[0]=1;
	for (int x=s-1; x!=0; x--){
		while (out[y]==9){
			y--;
		}
		out[y]++;
	}
	for (int i=0; i<m; i++){
		cout<<out[i];
	}
	cout<<' ';
	
	
	for (int i=0; i<k; i++){
		cout<<9;
	}
	if (k!=m) cout<<s%9;
	
	for (int i=k+1; i<m; i++){
		cout<<0;
	}
	cout<<endl;
	
	return 0;
}