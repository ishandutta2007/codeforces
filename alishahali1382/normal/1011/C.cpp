#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long double ld; 

int A[1001], B[1001];
int n, m;

bool simulate(ld ans){
	for (int i=1; i<n; i++){
		ans-=(m+ans)/A[i];
		if (ans<0) return false;
		ans-=(m+ans)/B[i+1];
		if (ans<0) return false;
	}
	ans-=(m+ans)/A[n];
	if (ans<0) return false;
	ans-=(m+ans)/B[1];
	if (ans<0) return false;
	return true;
}

ld limit=1e-10;

ld calc(ld l, ld r){
	ld mid=(l+r)/2;
	if (r-l<=limit){
		return mid;
	}
	if(simulate(mid)){
		return calc(l,mid);
	}
	return calc(mid,r);
}

int main(){
	cin>>n>>m;
	bool f=false;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		if(A[i]==1) f=true;
	}
	for (int i=1; i<=n; i++){
		cin>>B[i];
		if(B[i]==1) f=true;
	}
	ld ans=calc(0,100000000000);
	if(!simulate(1000000000000)||f){
		cout<<-1<<endl;
	}
	else{
		cout<<fixed<<setprecision(9)<<ans<<endl;
	}
	
	return 0;
}