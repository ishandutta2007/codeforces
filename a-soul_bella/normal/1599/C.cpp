/*
n, choose k

k*(k-1)*(k-2)/3 : 1

k*(n-k)*(n-k-1)/2 : 1/2

k/n: k-1/n-2

1/n: k/n-1

(n-k-1)/n: k/n-2

n(n-1)(n-2) fenzhi k(k-1)(n-1)+k(n-2)+(n-k-1)k(n-1) = nk(n-2)

n-1 k


*/
#include<bits/stdc++.h>
#define eps 1e-8
using namespace std;
int n;
double p;
double Possi(int x){
	double sum=0;
	sum+=x*(x-1)*(x-2)/6;
	sum+=x*(x-1)*(n-x)/2;
	sum+=(double)(x*(n-x)*(n-x-1))/4.0;
	return sum/(double)(n*(n-1)*(n-2)/6);
}
int main(){
	cin>>n>>p;
	for(int i=0;i<n;i++){
		if(Possi(i)>=p){
			cout<<i<<endl;
			break;
		}
	}
}