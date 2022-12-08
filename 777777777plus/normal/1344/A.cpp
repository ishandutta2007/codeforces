#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T;
int n,a[N],c[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)c[i]=0;
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			c[((i+a[i])%n+n)%n]++;
		}
		bool flag=1;
		for(int i=0;i<n;++i)if(!c[i])flag=0;
		if(flag)puts("YES");
		else puts("NO");
	}
}