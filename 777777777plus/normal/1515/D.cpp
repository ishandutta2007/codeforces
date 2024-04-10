#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T;
int n,l,r,a[N],b[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>l>>r;
		for(int i=1;i<=n;++i)a[i]=b[i]=0;
		for(int i=1,x;i<=l;++i)scanf("%d",&x),a[x]++;
		for(int i=1,x;i<=r;++i)scanf("%d",&x),b[x]++;
		int ans=0,ca=0,wa=0,cb=0,wb=0;
		for(int i=1;i<=n;++i){
			int x=min(a[i],b[i]);
			a[i]-=x;
			b[i]-=x;
			if(a[i]){
				wa+=a[i]/2;
				if(a[i]&1)++ca;
			}
			if(b[i]){
				wb+=b[i]/2;
				if(b[i]&1)++cb;
			}
		}
		int x=min(ca,cb);
		ans+=x;
		ca-=x;
		cb-=x;
		while(ca>=2&&wb)ca-=2,wb--,ans+=2;
		while(cb>=2&&wa)cb-=2,wa--,ans+=2;
		ans+=wa+wb;
		ans+=ca+cb;
		cout<<ans<<endl;
	}
}