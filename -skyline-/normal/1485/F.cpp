#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n;
ll a[200005];
map<ll,int> m;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%I64d",a+i),a[i]+=a[i-1];
		m.clear();
		m[0]=1;
		int s=1;
		for(int i=1;i<n;++i){
			int S=(s*2-m[a[i]])%orz;
			if(S<0)S+=orz;
			m[a[i]]=s;
			s=S;
		}
		printf("%d\n",s);
	}
    return 0;
}