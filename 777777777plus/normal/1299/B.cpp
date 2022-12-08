#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n,x[N],y[N];
double totx,toty;

int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>x[i]>>y[i];
		totx+=x[i];toty+=y[i];
	}
	totx/=n;toty/=n;
	bool flag=1;
	for(int i=0;i<n;++i){
		double x1=totx-x[i],y1=toty-y[i];
		x1+=totx,y1+=toty;
		if(abs(x1-x[(i+n/2)%n])>1e-8)flag=0;
		if(abs(y1-y[(i+n/2)%n])>1e-8)flag=0;
	}
	if(flag)cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}