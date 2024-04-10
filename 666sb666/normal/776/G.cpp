#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector> 
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
inline int read(){
	int a=0,f=1; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
	while(c>='0'&&c<='9')a=a*10+c-'0',c=getchar();
	return a*f;
}
inline int c(int x,int y){return x==y;}
ll f[20][2][2];int w,ww;
inline void aa(int maxi,int i,int j,int k,vector<int>&num){
	if(w==i){
		if(j==1){
			rep(x,0,min(maxi,num[i]))if(x>>ww&1)f[i][j&&c(x,num[i])][k||c(x,maxi)]+=f[i-1][j][k];
		}else{
			rep(x,0,maxi)if(x>>ww&1)f[i][j&&c(x,num[i])][k||c(x,maxi)]+=f[i-1][j][k];
		}
	}else{
		if(j==1){
			rep(x,0,min(maxi,num[i]))f[i][j&&c(x,num[i])][k||c(x,maxi)]+=f[i-1][j][k];
		}else{
			rep(x,0,maxi)f[i][j&&c(x,num[i])][k||c(x,maxi)]+=f[i-1][j][k];
		}
	}
}
inline int Check(vector<int>num){
	int maxi=0;
	rep(i,0,num.size()-1)maxi=max(maxi,num[i]);
	int w=num.size()-1-maxi/4,ww=maxi%4;
	if(w<0)return 0;
	if(num[w]>>ww&1)return 1;
	return 0;
}
inline ll DP(vector<int>num){
	ll ans=0;
	rep(maxi,0,15){
		memset(f,0,sizeof f);
		w=num.size()-1-maxi/4; ww=maxi%4;
		if(w<0)continue;
		if(!w){
			rep(i,0,min(maxi,num[0]))if(i>>ww&1)f[0][c(i,num[0])][c(i,maxi)]++;
		}else{
			rep(i,0,min(maxi,num[0]))f[0][c(i,num[0])][c(i,maxi)]++;
		}
		rep(i,1,num.size()-1)rep(j,0,1)rep(k,0,1)aa(maxi,i,j,k,num);
		ans+=f[num.size()-1][1][1]+f[num.size()-1][0][1];
	}
	return ans;
}
string str;
int main(){
	int q=read();
	while(q--){
		cin>>str;
		vector<int>L,R;
		rep(i,0,str.length()-1){
			if(str[i]>='0'&&str[i]<='9')L.push_back(str[i]-'0');
			else L.push_back(str[i]-'a'+10);
		}
		cin>>str;
		rep(i,0,str.length()-1){
			if(str[i]>='0'&&str[i]<='9')R.push_back(str[i]-'0');
			else R.push_back(str[i]-'a'+10);
		}
		printf("%lld\n",DP(R)-DP(L)+Check(L));
	}
	return 0;
}