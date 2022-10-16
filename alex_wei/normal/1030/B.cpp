#include<bits/stdc++.h>
using namespace std;
#define ll long long
int d,n,m,x,y; 
int main(){
	cin>>n>>d>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		if(x+y>=d&&x+y<=n*2-d&&abs(x-y)<=d)puts("YES");
		else puts("NO");
	}
    return 0;
}