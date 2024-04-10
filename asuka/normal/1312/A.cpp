#include<bits/stdc++.h>
#define ll long long
#define N
using namespace std;
int t,n,m; 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>m>>n;
		if(m%n==0) puts("YES");
		else puts("NO");
	}
	return 0;
}