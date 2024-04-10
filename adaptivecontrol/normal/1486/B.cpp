#include<bits/stdc++.h>
using namespace std;
int T,n,x[1003],y[1003];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d%d",x+i,y+i);
		sort(x,x+n);sort(y,y+n);
		if(n%2)
			cout<<1<<endl;
		else
			cout<<1ll*(x[n/2]-x[n/2-1]+1)*(y[n/2]-y[n/2-1]+1)<<endl;
	}
}