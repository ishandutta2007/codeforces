#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
basic_string<int>a,b;
int main(){
	int n,m,l=0,r=1e9,i,j,x;
	cin>>n;
	while(l<=r){
		m=l+r>>1;
		cout<<"> "<<m<<endl;
		cin>>i;
		if(i)l=m+1;
		else r=m-1;
	}
	for(i=n;i;--i)a+=i;
	shuffle(a.begin(),a.end(),default_random_engine(1437));
	for(i=min(n-1,28);~i;--i){
		cout<<"? "<<a[i]<<endl;
		cin>>j,b+=j;
	}
	sort(b.begin(),b.end()),j=b.size(),x=b[1]-b[0];
	for(i=2;i<j;++i)x=gcd(x,b[i]-b[i-1]);
	cout<<"! "<<r+1-(n-1)*x<<' '<<x<<endl;
	return 0;
}