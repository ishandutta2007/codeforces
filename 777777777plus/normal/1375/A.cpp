#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i){
			if(i&1)printf("%d ",abs(a[i]));
			else printf("%d ",-abs(a[i]));
		}
		printf("\n");
	}
}