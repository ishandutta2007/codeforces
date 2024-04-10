#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
struct node{
	int a,b;
	double price;
}c[5005];
int n,m;
double sum;
bool cmp(const node &x, const node &y){
	return x.price < y.price;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&c[i].a,&c[i].b);
		c[i].price = 1.0*c[i].a/c[i].b;
	}
	
	sort(c+1,c+n+1,cmp);
	
	printf("%.8lf\n",m * c[1].price);
	return 0;
}