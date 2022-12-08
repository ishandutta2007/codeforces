#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;

int T;
int n,x,y;

bool can1(int c){
	int x1=max(n-c-1,x),y1=max(n-c-1,y);
	int w1=n+n-c,w2=n+n-c-1;
	int c2=x1+y1-w1;
	if(c2)return w2>x+y;
	else return w1>x+y;
}

bool can2(int c){
	int x1=min(c+1,x),y1=min(c+1,y);
	int w1=1+c,w2=c;
	int c2=x1+y1-w1;
	if(c2)return w2<=x+y;
	else return w1<=x+y;
}

int sol1(){
	int l=1,r=n;
	while(l!=r){
		int mid=l+r>>1;
		if(can1(n-mid))r=mid;
		else l=mid+1;
	}
	return l;
}

int sol2(){
	int l=1,r=n;
	while(l!=r){
		int mid=l+r+1>>1;
		if(can2(mid-1))l=mid;
		else r=mid-1;
	}
	return l;
}

int main(){
	cin>>T;
	while(T--){
		cin>>n>>x>>y;
		if(x+y<=n){
			cout<<1<<" ";
		}
		else{
			cout<<min(x+y+1-n,n)<<" ";
		}
		if(x+y>n){
			cout<<n<<endl;
		}
		else{
			cout<<x+y-1<<endl;
		}
	}
}