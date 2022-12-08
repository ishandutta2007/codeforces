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
		db c=cos(d);
		db ans=sqrt(1.-c*c)/c;
		printf("%.10f\n",ans);
	}
}