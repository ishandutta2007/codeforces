#include<bits/stdc++.h>
#define int long long
#define N 1015
using namespace std;
int n,a[N],b[N],ans,a1,pos;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1;i <= n;++i) scanf("%lld",&a[i]);
	for(int i = 0;i <= n;++i){
		int minn = 0x3f3f3f3f3f3f3f3f;
		a1 = 0;
		for(int j = i;j > 0;--j){
			if(a[j] < minn){
				a1 += a[j];
				minn = a[j];
			}else{
				a1 += minn;
			}
		}
		minn = 0x3f3f3f3f3f3f3f3f;
		for(int j = i+1;j <= n;++j){
			if(a[j] < minn){
				a1 += a[j];
				minn = a[j];
			}else{
				a1 += minn;
			}
		}
		if(ans < a1) ans = a1,pos = i;
	}
	int minn = 0x3f3f3f3f3f3f3f3f;
	for(int i = pos;i > 0;--i){
		if(a[i] < minn){
			b[i] = a[i];
			minn = a[i];
		}else{
			b[i] = minn;
		}
	}
	minn = 0x3f3f3f3f3f3f3f3f;
	for(int i = pos+1;i <= n;++i){
		if(a[i] < minn){
			b[i] = a[i];
			minn = a[i];
		}else{
			b[i] = minn;
		}
	}
	for(int i = 1;i <= n;++i){
		printf("%lld ",b[i]);
	}
	return 0;
}