#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long n, m, s, ss;
int A[100000 + 10];
int B[100000 + 10];
int C[100000 + 10];

int main(){
	//freopen("input.txt", "r", stdin);
	cin>>n>>m;
	for (int i=0; i<n; i++){
		cin>>A[i]>>B[i];
		C[i]=A[i]-B[i];
		s+=A[i];
		ss+=B[i];
	}
	if (ss>m){
		cout<<-1<<endl;
		return 0;
	}
	sort(C, C+n);
	reverse(C, C+n);
	for (int i=0; i<n; i++){
		if (s<=m){
			cout<<i<<endl;
			return 0;
		}
		s-=C[i];
	}
	if (s<=m){
		cout<<n<<endl;
		return 0;
	}
	cout<<-1<<endl;
	return 0;
}