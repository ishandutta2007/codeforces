#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, x;
long long ans;
int A[501][501];
int B[501][501];
int X[501];
long long out[501];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin>>A[i][j];
		}
	}
	
	for (int i=0; i<n; i++){
		cin>>X[i];
		X[i]--;
	}
	
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			B[i][j]=A[X[n-i-1]][X[n-j-1]];
		}
	}
	/*
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cout<<B[i][j]<<' ';
		}
		cout<<endl;
	}*/
	
	for (int k=0; k<n; k++){
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				B[i][j]=min(B[i][j], B[i][k] + B[k][j]);
			}
		}
		/*
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				cout<<B[i][j]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;*/
		
		ans=0;
		for (int i=0; i<=k; i++){
			for (int j=0; j<=k; j++){
				ans+=B[i][j];
			}
		}
		out[n-k-1]=ans;
	}
	for (int i=0; i<n; i++){
		cout<<out[i]<<' ';
	}
	cout<<endl;
	
	return 0;
}