#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 2e5+5;
const db pi = acos(-1);

int T;
int n;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		n<<=1;
		db d=pi*(n-2)/n/2;
		db c=1./cos(d);
		db d1=2*pi/n/4;
		printf("%.10f\n",c*cos(d1));
	}
}