#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int inv10=700000005;
int sum[100100][2],num[100100][2],ans[100100][2],n,res;
//sum[i][j]:the sum of numbers whose length is i and begin with number j.
//num[i][j]:the amount of so [except the boundary value,which is x7777...]
//ans[i][j]:the answer of so [except the boundary value,which is (x7777...)*(y4444...)]
char s[100100];
int func(){
//	for(int i=n-1;;i--){
//		if(i<0)return 0;
//		if(s[i]=='7'){s[i]='4';break;}
//		s[i]='7';
//	}
	int _74=7,_47=4,_10=10,_4=4;
	for(int i=1;i<n;i++)_74=(10ll*_74+4)%mod,_47=(10ll*_47+7)%mod,_10=10ll*_10%mod,_4=(10ll*_4+4)%mod;
	int pref=0,ret=0;
	for(int i=0;i<n;i++){
		if(s[i]=='7'){
			int now=1ll*pref*_10%mod;
			int tmp=(2ll*sum[n-i-1][0]+(mod-_4)+(mod-_47))%mod;
			(ret+=(0ll+ans[n-i-1][0]+(1ll*now*now%mod)*num[n-i-1][0]%mod+1ll*now*tmp%mod+1ll*(now+_47)*(now+_74)%mod)%mod)%=mod;
		}
		pref=(10ll*pref+s[i]-'0')%mod;
		_74=1ll*(_74+mod-4)*inv10%mod,_47=1ll*(_47+mod-7)*inv10%mod,_10=1ll*_10*inv10%mod,_4=1ll*(_4+mod-4)*inv10%mod;
	}
	return ret;
}
int main(){
	scanf("%s",s),n=strlen(s);
    sum[0][0]=4,sum[0][1]=7;
    int _74=7,_47=4,_10=10,_7=7,_4=4;//74444...;47777...;1000...;7777...;4444....
    for(int i=1;i<n;i++){
    	int __4=4ll*_10%mod,__7=7ll*_10%mod;//4000...;7000...;
    	int tmp=(2ll*(sum[i-1][0]+sum[i-1][1])+(mod-_7)+(mod-_4))%mod;//the sum of the previous stage,except the two boundary values
        num[i][0]=(num[i-1][0]+num[i-1][1]+1)%mod;//+1 because after adding a number in the beginning, one previous boundary value is no longer hold.
        num[i][1]=(num[i-1][0]+num[i-1][1]+1)%mod;//num[i][0] always equals to num[i][1]; however we keep them both so as to distinguish them.
        ans[i][0]=(0ll+(1ll*_74*_47%mod+ans[i-1][0]+ans[i-1][1])%mod+(1ll*__4*__4%mod)*num[i][0]%mod+1ll*__4*tmp%mod)%mod;
        ans[i][1]=(0ll+(1ll*_74*_47%mod+ans[i-1][0]+ans[i-1][1])%mod+(1ll*__7*__7%mod)*num[i][1]%mod+1ll*__7*tmp%mod)%mod;
//consider using the equation (k+x)(k+y)=k^2+k(x+y)+xy,and you'll find why the transmission is like this.[remember to consider the no-longer boundary]
        sum[i][0]=(1ll*__4*(num[i][0]+1)%mod+sum[i-1][0]+sum[i-1][1])%mod;//still there's +1.
        sum[i][1]=(1ll*__7*(num[i][1]+1)%mod+sum[i-1][0]+sum[i-1][1])%mod;
        _74=(10ll*_74+4)%mod,_47=(10ll*_47+7)%mod,_7=(10ll*_7+7)%mod,_4=(10ll*_4+4)%mod,_10=10ll*_10%mod;
	}
	res=(mod-func())%mod;
	scanf("%s",s);
	(res+=func())%=mod;
	printf("%d\n",res);
	return 0;
}