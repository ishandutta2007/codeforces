#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

const int sg[31]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12,14};
int main(){
	AquA;
	long long n;
	cin >> n;
	int ans=0;
	int z=n;
	map<int,int> m;
	for(long long i=2;i*i<=n;i++){
		long long k=1,l=0;
		if(m[i]==1){
			continue;
		}
		while(1){
			k*=i;
			if(k>n){
				break;
			}
			m[k]=1;
			l++;
		}
		z-=l;
		//cout << i << " " << l << "\n";
		ans^=sg[l];
	}
	if(z%2){
		ans^=1;
	}
	if(ans){
		cout << "Vasya\n";
	}
	else{
		cout << "Petya\n";
	}
	return 0;
}