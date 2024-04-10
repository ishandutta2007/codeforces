#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
const ll inf = (ll)1e18;
int n,m;
ll a[55],b[55];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for(int j=1;j<=m;j++) scanf("%I64d",&b[j]);
	int maxpos = 0;
	ll maxpro = -inf;
	int hide = 0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i] * b[j] > maxpro){
				maxpro = a[i] * b[j];
				hide = i;
			}
		}
	}
	
	maxpro = -inf;
	for(int i=1;i<=n;i++){
		if(hide == i) continue;
		for(int j=1;j<=m;j++){
			if(a[i] * b[j] > maxpro){
				maxpro = a[i] * b[j];
			}
		}
	}
	printf("%I64d",maxpro);
	return 0;
}