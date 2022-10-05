#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int n,m,ans=11,mina=11,minb=11;
	cin>>n>>m;
	int a[n],b[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
		mina=min(mina,a[i]);
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
		minb=min(minb,b[i]);
		for(int j=0;j<n;j++)if(b[i]==a[j]) ans=min(ans,a[j]);	
	}
	if(ans!=11)cout<<ans;
	else cout<<min(mina,minb)<<max(mina,minb);
	return 0;
}