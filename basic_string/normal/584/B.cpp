#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int main(){
	int n,u=1,v=1;
	cin>>n;while(n--)u=u*27ll%P,v=v*7ll%P;cout<<(u-v+P)%P;
	return 0;
}