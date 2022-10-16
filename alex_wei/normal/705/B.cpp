#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a,s; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		s+=a-1;
		if(s%2)puts("1");
		else puts("2");
	}
    return 0;
}