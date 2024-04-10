#include<bits/stdc++.h>
using namespace std;
#define ll long long
// k>x+y!!
/*
5 4 5 3 3
5 5 3 3
*/
ll n,t,a,b,k,x,y;
int main(){
	cin>>n>>t>>a>>b>>k;
	y=t/2;
	x=t-y; 
	if(a<b) swap(a,b),swap(x,y);
	if(t<k){
		cout<<0;
		return 0;
	}
	if(k<=x){
		cout<<min(n,(a*x+b*y)/k);
		return 0;
	}
	ll p=min(a,(y*b)/(k-x));
	if(a-p<=b-((k-x)*p)/y) cout<<min(n,(a*x+b*y)/k);
	else cout<<min(n,p);
}