#include<bits/stdc++.h>
using namespace std;
int n,mid,l,r;
int input(int x,int y){
	if(x==y)return -1;
	if(x>y)swap(x,y);
	cout<<"? "<<x<<' '<<y<<endl;
	cin>>x;return x;
}
int main(){
	cin>>n;
	cout<<"? 1 "<<n<<endl;
	cin>>mid;
	int x;
	x=input(1,mid);
	if(x==mid){
		l=1;r=mid-1;
		while(l!=r){
			int nwmid=(l+r+1)/2,read=input(nwmid,mid);
			if(read==mid)
				l=nwmid;
			else
				r=nwmid-1;
		}
	}
	else{
		l=mid+1;r=n;
		while(l!=r){
			int nwmid=(l+r)/2,read=input(mid,nwmid);
			if(read==mid)
				r=nwmid;
			else
				l=nwmid+1;
		}
	}cout<<"! "<<l;
}