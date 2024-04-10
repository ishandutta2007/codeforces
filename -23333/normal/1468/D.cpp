#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2e6;
int n,m,a,b;
int s[N],ms,tim;
inline bool check(int pos){
	if(pos>ms)return 0;
	int lim=tim;
	//cout<<pos<<endl;
	for(int i=pos;i>=1;--i){
		lim--;
	//	cout<<lim<<" "<<s[i]<<endl;
		if(lim<s[i])return 0;
	}
	return 1;
}
int main()
{
	int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&m,&a,&b);
        ms=abs(a-b)-1;
        tim=ms;
        if(a<b)tim+=a;
        else tim+=n-a+1;
        for(int i=1;i<=m;++i){
		    scanf("%d",&s[i]);
		}
		sort(s+1,s+m+1);
		int l=0,r=m,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)){
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		printf("%d\n",ans);
    }
	return 0;
	
}