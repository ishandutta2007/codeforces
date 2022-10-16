#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
ll n,m,p,a[N],b[N];
int main(){
	scanf("%lld%lld%lld",&n,&m,&p);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	for(int i=0;i<m;i++)scanf("%lld",&b[i]);
	int l;
	for(int i=0;i<n;i++)if(a[i]%p){
		l=i;
		break;
	}
	for(int i=0;i<m;i++)if(b[i]%p){
		cout<<l+i,exit(0);
	}
	return 0;
}