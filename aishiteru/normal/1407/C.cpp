#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
int a[N],o,n;
il void que(ct x,ct y){cout<<'?'<<' '<<x<<' '<<y<<endl,cout<<flush,cin>>o;}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;it i,pos=1,o1,o2;
	for(i=2;i<=n;++i){
		que(i,pos),o1=o,que(pos,i),o2=o;
		if(o1>o2) a[i]=o1;
		else a[pos]=o2,pos=i;
	}
	a[pos]=n;
	cout<<'!';for(i=1;i<=n;++i) cout<<' '<<a[i];cout<<endl,cout<<flush;
	return 0;
}