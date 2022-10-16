#include<iostream>
using namespace std;
typedef long long LL;
LL t,n,p,q,f;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	for(cin>>t;t--;){
		for(cin>>n,q=(f=0)+n;n--;q=p) cin>>p, f|=(p-q>1);
		puts(f?"No":"Yes");
	}
	return 0;
}