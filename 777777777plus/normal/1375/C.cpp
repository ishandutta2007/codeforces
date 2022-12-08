#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;

int T;
int n,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		if(a[1]<a[n])printf("YES\n");
		else printf("NO\n");
	}
}