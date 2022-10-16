#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
int main(){
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		if(n%m==0)puts("YES");
		else puts("NO");
	}
	return 0;
}