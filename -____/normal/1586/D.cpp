#include<bits/stdc++.h>
using namespace std;
const int N = 111;
int n,a[N],b[N],p[N];
int go(int x,int y){
	int i;
	cout<<"? ";
	for(i=1;i<n;i++)
		cout<<x+1<<' ';
	cout<<y+1<<endl;
	cin>>x;
	return x;
}
int main(){
	int i,x,y;
	cin>>n;
	for(i=1;i<=n;i++){
		if(i==n){
			x=n;
			break;
		}
		a[i]=go(0,i);
		if(!a[i]){
			x=i;
			break;
		}
	}
	for(i=1;i<=n-x;i++)
		b[i]=go(i,0);
	y=0;
	for(i=n-x;i>=1;i--)
		p[b[i]]=++y;
	p[n]=++y;
	for(i=1;i<=x;i++)
		p[a[i]]=++y;
	cout<<"! ";
	for(i=1;i<=n;i++)
		cout<<p[i]<<' ';
	cout<<endl;
	return 0;
}