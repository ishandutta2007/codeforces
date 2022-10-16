#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int s,x1,x2,t1,t2,p,d,ans,ts,te;
int calc(int pos,int to,int &dir){
	if(dir==1){
		if(pos<=to)return to-pos;
		else{
			dir=-1;
			return 2*s-pos-to;
		}
	}
	else{
		if(pos>=to)return pos-to;
		else{
			dir=1;
			return to+pos;
		}
	}
}
int main(){
	cin>>s>>x1>>x2>>t2>>t1>>p>>d;
	cout<<min(abs(x1-x2)*t1,t2*(calc(p,x1,d)+calc(x1,x2,d)));
	return 0;
}
////