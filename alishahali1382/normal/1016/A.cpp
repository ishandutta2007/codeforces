#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m, x;
int A[200 * 1000 + 10];
string s;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n>>m;
	for (int i=0; i<n; i++){
		cin>>A[i];
		x+=A[i];
		cout<<x/m<<' ';
		x%=m;
	}
	cout<<endl;
	return 0;
}