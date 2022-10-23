#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n;
ll ans;
ll a[1005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%I64d",a+i);
	for(int i=1;i<=n;i+=2){
		ll o=0,p=a[i];
		for(int j=i;j<=n;++j){
			if(j&1)o+=a[j];
			else{
				o-=a[j];
				if(o>=0)ans+=max(0ll,min(min(a[i]-o,a[j]),p-o+1));
				else{
					ans+=max(0ll,min(min(a[i],a[j]+o),p+1));
					break;
				}
				p=min(p,o);
			}
		}
	}
	printf("%I64d\n",ans);
    return 0;
}