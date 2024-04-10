#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
int p,m,n,S,b[4010],f[4010][4010][2][2];
char s[1010];
ll a[1010];
int dfs(int pos,int num,bool lim,bool car){
	if(pos<0){return num>=m&&!car;}
	int&res=f[pos][num][lim][car];if(res!=-1)return res;res=0;
	if(lim){
		res=(1ll*(p-abs(car*p+b[pos]-(p-1)))*dfs(pos-1,num+car,true,false)+res)%mod;
		res=(1ll*(p-abs(car*p+b[pos]-1-(p-1)))*dfs(pos-1,num+car,true,true)+res)%mod;
		if(car){
			res=((1ll*(p-1+p-b[pos])*b[pos]/2)%mod*dfs(pos-1,num+car,false,false)+res)%mod;
			res=((1ll*(p+1+p-b[pos])*b[pos]/2)%mod*dfs(pos-1,num+car,false,true)+res)%mod;
		}else{
			res=((1ll*(b[pos]+1)*b[pos]/2)%mod*dfs(pos-1,num+car,false,false)+res)%mod;
			res=((1ll*(b[pos]-1)*b[pos]/2)%mod*dfs(pos-1,num+car,false,true)+res)%mod;
		}
		return res;
	}
	if(car){
		res=((1ll*p*(p-1)/2)%mod*dfs(pos-1,num+car,false,false)+res)%mod;
		res=((1ll*(p+1)*p/2)%mod*dfs(pos-1,num+car,false,true)+res)%mod;
	}else{
		res=((1ll*(p+1)*p/2)%mod*dfs(pos-1,num+car,false,false)+res)%mod;
		res=((1ll*p*(p-1)/2)%mod*dfs(pos-1,num+car,false,true)+res)%mod;
	}
	return res;
}
int main(){
	scanf("%d%d%s",&p,&m,s),S=strlen(s);
	reverse(s,s+S);
	for(int i=0;i<S;i++)a[i]=s[i]-'0';
	while(S){
		int rem=0;
		for(int i=S-1;i>=0;i--)rem=(10ll*rem+a[i])%p;
		b[n++]=rem;
		for(int i=S-1;i>=0;i--){
			if(i)a[i-1]+=a[i]%p*10;
			a[i]/=p;
		}
		while(S&&!a[S-1])S--;
	}
	memset(f,-1,sizeof(f));
	printf("%d\n",dfs(n-1,0,true,false));
//	for(int i=n-1;i>=0;i--)printf("%d ",b[i]);puts("");
	return 0;
}