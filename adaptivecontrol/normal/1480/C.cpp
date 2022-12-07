#include<bits/stdc++.h>
using namespace std;
int n;
int input(int x){
	if(x==0||x==n+1)return 19260817;
	cout<<"? "<<x<<endl;
	fflush(stdout);
	cin>>x;return x; 
}
bool check(int x){
	return input(x)<input(x+1);
}
int main(){
	cin>>n;
	int l=1,r=n;
	while(l!=r){
		int mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	cout<<"! "<<l;
	fflush(stdout);
}