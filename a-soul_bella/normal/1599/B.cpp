#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n;
int a,b,_a,_b;
int la,lb,l_a,l_b;
int ans;
int readchar(){
	char xx=0;
	while(xx!='l' && xx!='r') xx=getchar();
	if(xx=='l'){
		for(int i=1;i<=3;i++) xx=getchar();
		return 0;
	}
	else{
		for(int i=1;i<=4;i++) xx=getchar();
		return 1;
	}
}
signed main(){
	scanf("%lld",&T);
	while(T--){
		bool swp=false;
		//int MainTain=-1;
		scanf("%lld",&n);
		scanf("%lld %lld",&a,&b);
		_a=readchar(),_b=readchar();
		ans=0;
		bool rem=false;
		if(_a) swp=true,a=n-a-1,b=n-b-1,_a=(!_a),_b=(!_b);
		if(_b==1){
			if(a>=b) rem=true;
			int qwq=min(a,n-b-1);
			a-=qwq,b+=qwq;
			if(a==0) swp=(!swp),a=n-a-1,b=n-b-1;
			_b=0;
			if(rem){
				if(abs(a-b)>1) a--;
				else if(abs(a-b)==1) a=n-1,b=n-2;
			}
		}
		if(_b==0){
			if(a<b){
				int K=b-a;
				//+(K+1)/2
				if(K&1) ans=0;
				else ans=n-1;
			}				
			else if(a==b){
				if(a<n-1) ans=n-1;
				else ans=0;
			}
			else if(a>b){
				int K=a-b;
				if(K&1) ans=n-1;
				else ans=0;
			}
		}
		if(!swp) printf("%lld\n",ans);
		else printf("%lld\n",n-1-ans);
	}
	return 0;
}