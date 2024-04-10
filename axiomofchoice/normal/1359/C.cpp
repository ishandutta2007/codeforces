#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll;
#define int ll
typedef long double lf;
int T,h,c,t;
signed main(){
	cin>>T;
	while(T--){
		cin>>h>>c>>t;
		if(t<=(h+c)/2){cout<<2<<endl; continue;}
		lf t2=(t-lf(h+c)/2)/(h-c);
		lf t3=floor(1/(4*t2)-0.5);
		int x=llround(t3),y=x+1;
		if(abs(lf(1)/(4*x+2)-t2)<=abs(lf(1)/(4*y+2)-t2))
			cout<<x*2+1<<endl;
		else
			cout<<y*2+1<<endl;
	}
	return 0;
}