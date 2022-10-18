#include <bits/stdc++.h>
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

long long x;
bool f(long long a,long long b){
	if(a<b){
		swap(a,b);
	}
	if(a<x && b<x){
		return 0;
	}
	if((a-x)%b==0){
		return 1;
	}
	if(x%__gcd(a,b)){
		return 0;
	}
	return f(a%b,b);
}
int main(){
	AquA;
	int t;
	cin >> t;
	while(t--){
		long long a,b;
		cin >> a >> b >> x;
		cout << (f(a,b)?"Yes":"No") << "\n";
	}
	return 0;
}