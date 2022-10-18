#include <bits/stdc++.h>
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int cmpz(pair<long double,int> a,pair<long double,int> b){
	if(a.sc==b.sc && a.fs==b.fs){
		return 0;
	}
	if(a.sc!=b.sc){
		if(a.sc>b.sc){
			return 1;
		}
		return -1;
	}
	if(a.fs>b.fs){
		return 1;
	}
	return -1;
}
int main(){
	AquA;	
	int t;
	cin >> t;
	while(t--){
		pair<long double,int> a,b;
		cin >> a.fs >> a.sc >> b.fs >> b.sc;
		while(a.fs>=10){
			a.fs/=10.0;
			a.sc++;
		}
		while(b.fs>=10){
			b.fs/=10.0;
			b.sc++;
		}
		int h=cmpz(a,b);
		if(h==0){
			cout << "=\n";
		}
		else if(h==1){
			cout << ">\n";
		}
		else{
			cout << "<\n";
		}
	}
	return 0;
}