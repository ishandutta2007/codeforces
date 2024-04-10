#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
int a,b;
int main(){
	cin>>t;
	while(t--){
	 	cin>>a>>b;
	 	if(a==b)puts("0");
	 	else if(a<b&&a%2!=b%2||a>b&&a%2==b%2)puts("1");
	 	else puts("2");
	}
	return 0;
}