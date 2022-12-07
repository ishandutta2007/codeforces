#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100005
using namespace std;
typedef long long ll;
int n,a,b,s[maxn],S;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		S += s[i];
	}
	sort(s+2,s+n+1);
	for(int i=n;i>=1;i--){
		if((ll)s[1] * a >= (ll)S * b){
			printf("%d\n",n-i);
			return 0;
		}
		S -= s[i];
	}
	return 0;
}