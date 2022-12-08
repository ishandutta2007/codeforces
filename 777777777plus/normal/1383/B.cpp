#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,a[N];

void Solve(){
	for(int i=30;~i;--i){
		int cnt1=0,cnt2=0;
		for(int j=1;j<=n;++j)
		if(a[j]&1<<i)cnt1++;
		else cnt2++;
		if(cnt1%2){
			int a1=cnt1+1>>1;
			if(a1%2)puts("WIN");
			else if(cnt2%2)puts("WIN");
			else puts("LOSE");
			return;
		}
	}
	puts("DRAW");
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		Solve();
	}
}