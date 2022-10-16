#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m,n,d,r;
int main(){
	cin>>n>>m;
	d=n/m;
	r=n%m;
	cout<<(m-r)*(d-1)*d/2+r*d*(r==0?d-1:d+1)/2<<" "<<(n-m)*(n-m+1)/2;
    return 0;
}