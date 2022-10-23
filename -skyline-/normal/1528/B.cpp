#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  998244353
using namespace std;
ll f[1000005],s;
int n;
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		for(int j=i;j<=n;j+=i)++f[j];
	}
	f[0]=1;
	s=1;
	for(int i=1;i<=n;++i){
		(f[i]+=s)%=orz;
		(s+=f[i])%=orz;
	}
	printf("%I64d\n",f[n]);
    return 0;
}