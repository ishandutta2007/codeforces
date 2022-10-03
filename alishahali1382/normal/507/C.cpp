#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long h, n, ans;

int main(){
	cin>>h>>n;
	n--;
	int l=0, j=0;
	int A[h];
	for (int i=h-1; i>=0; i--){
		if ((1LL<<i)&n){
			A[j++]=1;
		}
		else{
			A[j++]=0;
		}
	}
	for (int i=0; i<h; i++){
		if (l==A[i]){
			l=1-l;
			ans++;
		}
		else{
			ans+=(1LL<<(h-i));
		}
	}
	cout<<ans<<endl;

	return 0;
}