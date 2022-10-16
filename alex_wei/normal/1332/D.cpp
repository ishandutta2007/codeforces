#include <bits/stdc++.h>
using namespace std;
#define ll long long
int k,a[505][505];
const int inf=(1<<18)-1;
int main(){
	cin>>k;
	cout<<"4 5\n";
	a[1][1]=inf,a[1][2]=k,a[2][1]=inf-k;
	for(int i=2;i<=4;i++){
		a[1][i]=a[i][4]=k;
		a[i][1]=a[4][i]=inf-k;
	}
	a[4][4]=inf,a[4][5]=k;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=5;j++)cout<<a[i][j]<<" ";
		puts("");
	}
	return 0; 
}