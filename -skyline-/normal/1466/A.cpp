#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int t,n,a[55],f[55];
int main(){
	scanf("%d",&t);
	for(int _=1;_<=t;++_){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		int ans=0;
		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j){
				if(f[a[j]-a[i]]!=_)f[a[j]-a[i]]=_,++ans;
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}