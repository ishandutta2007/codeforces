#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n;
ll b[N],a[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		ll tot=0;
		for(int i=0;i<n;++i)cin>>b[i],tot+=b[i];
		ll cnt=1ll*n*(n+1)/2;
		if(tot%cnt){
			puts("NO");
			continue;
		}
		tot/=cnt;
		bool flag=1;
		for(int i=0;i<n;++i){
			a[i]=b[(i-1+n)%n]-(b[i]-tot);
			if(a[i]%n){
				flag=0;
				break;
			}
			a[i]/=n;
		}
		for(int i=0;i<n;++i)
		if(a[i]<1||a[i]>1e9){
			flag=0;
			break;
		}
		if(!flag){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=0;i<n;++i)printf("%lld ",a[i]);
		printf("\n");
	}
}