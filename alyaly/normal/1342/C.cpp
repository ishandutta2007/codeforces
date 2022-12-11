#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,a,b,Q,l,r,ab,ans;
int gcd(int x,int y){
	if(x>y) swap(x,y);
	return (y%x==0)?x:gcd(x,y%x);
}
signed main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>Q;
		if(a>b) swap(a,b);
		ab=a/gcd(a,b)*b;
		for(int i=1;i<=Q;i++){
			cin>>l>>r;
			if(a==b){
				printf("%lld\n",0ll);
				continue;
			}
//			if(l==100){
//				printf("a");
//				for(int i=l;i<=r;i++){
//					if(i%a==(i%b)%a) printf("%d\n",i);
//				}
//			}
			int tr=r,tl=l;
//			if(r-l<=2*ab){
//				ans=0;
//				for(int j=l;j<=r;j++){
//					if(j%a==(j%b)%a) ans++;
//				}
//				printf("%lld\n",ans);
//			}else{
//				l++;
//				r++;
				ans=0;
				if(l%ab<=b-1){
					ans+=(b-l%ab);
				}
				l=l-(l%ab)+ab;
				if(r%ab<=b-1){
					ans+=(r%ab+1);
				}else ans+=b;
				r=r-(r%ab)-1;
				ans+=(r-l+1)/ab*b;
//			}
//			printf("%lld\n",ans);
			printf("%lld ",tr-tl+1-ans);
		}
		printf("\n");
	}
	return 0;
}
/*

*/