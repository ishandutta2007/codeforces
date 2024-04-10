#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int n,a[N],s; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],s+=a[i];
	cout<<n-1+(s%n==0);
    return 0;
}