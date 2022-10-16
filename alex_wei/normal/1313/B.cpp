#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T;
int n,x,y;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>x>>y;
		cout<<min(max(1,x+y-n+1),n)<<" "<<min(n,x+y-1)<<endl;
	}
	return 0;
}