#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int n,a[N]; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)if(a[i]-a[i-1]>1)a[i]=a[i-1]+1;
	cout<<a[n]+1;
    return 0;
}