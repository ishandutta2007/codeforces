#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
long long num[10],ex;
bitset<13440> in;
int main(){
	long long w,ans=0;
	scanf("%lld",&w);
	in[0]=true;
	for(int i=1;i<=8;i++){
		scanf("%lld",&num[i]);
		if(num[i]/(840/i)>1){
			ex+=num[i]/(840/i)-1;
			num[i]=num[i]%(840/i)+(840/i);	
		}
		for(int j=0;j<num[i];j++){
			in|=in<<i;
		}
	}
	for(int i=0;i<13440&&i<=w;i++){
		if(in[i]) ans=max(ans,i+min((w-i)/840,ex)*840);
	}
	printf("%lld\n",ans);
	return 0;
}