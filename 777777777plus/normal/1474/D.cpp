#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int T;
int n;
ll a[N],b[N];
ll mnb[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<n;++i)b[i]=a[i]-b[i-1];
		bool flag=1;
		for(int i=1;i<n;++i)
		if(b[i]<0){
			flag=0;
			break;
		}
		if(flag&&b[n-1]==a[n]){
			puts("YES");
			continue;
		}
		mnb[n]=mnb[n+1]=mnb[n+2]=1e18;
		for(int i=n-1;i>=1;--i){
			mnb[i]=min(b[i],mnb[i+2]);
		}
		flag=0;
		for(int i=1;i<n;++i){
			if(b[i-1]<0){
				break;
			}
			ll bsp=b[i]-a[i]+a[i+1];
			if(bsp<0){
				continue;
			}
			ll mn0=mnb[i+1],mn1=mnb[i+2];
			mn0+=a[i]*2-a[i+1]*2;
			mn1+=a[i+1]*2-a[i]*2;
			if(mn0>=0&&mn1>=0){
				ll mnr=mnb[n-1];
				if((i+1&1)==(n-1&1)){
					mnr+=a[i]*2-a[i+1]*2;
				}
				else{
					mnr+=a[i+1]*2-a[i]*2;
				}
				if(mnr==a[n]){
					flag=1;
					puts("YES");
					break;
				}
			}
		}
		if(!flag){
			puts("NO");
		}
	}
}