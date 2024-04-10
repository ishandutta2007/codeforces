#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;
int out[101][101];
int A[101];
int B[101];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n>>m;
	for (int i=0; i<n; i++){
		cin>>A[i];
		x^=A[i];
	}
	for (int i=0; i<m; i++){
		cin>>B[i];
		y^=B[i];
	}
	//cout<<x<<' '<<y<<endl;
	if (x!=y){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	for (int i=0; i<m-1; i++){
		out[n-1][i]=B[i];
	}
	int tmp=0;
	for (int i=0; i<n-1; i++){
		out[i][m-1]=A[i];
		tmp^=A[i];
	}
	out[n-1][m-1]=tmp^B[m-1];
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cout<<out[i][j]<<' ';
		}
		cout<<endl;
	}
	
	return 0;
}