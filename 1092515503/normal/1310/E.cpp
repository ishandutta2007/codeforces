#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,res;
typedef vector<int> vi;
vi deco(vi v){
	vi u;
	for(int i=v.size()-1;i>=0;i--)for(int j=0;j<v[i];j++)u.push_back(i+1);
	return u;
}
#define sqr(x) x*(x+1)/2
bool che(vi v){
	if(sqr(v.size())>n)return false;
	for(int i=1;i<=m-2;i++){
		v=deco(v);
		if(sqr(v.size())>n)return false;
	}
	int sum=0;
	for(int i=0;i<v.size();i++)sum+=v[i]*(i+1);
	return sum<=n;
}
vi v;
void dfs(int x){
	for(int i=1;i<=x;i++){
		v.push_back(i);
		if(che(v))res++,dfs(i);
		v.pop_back();
	}
}
int f[2100][2100];//i numbers,sum equals to j.
void solve1(){
	f[0][0]=1;
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)
		f[i][j]=(f[i][j-i]+f[i-1][j-1])%mod,(res+=f[i][j])%=mod;
}
void solve2(){
	f[0][0]=1;
	for(int i=1;i<=n;i++)for(int j=i*(i+1)/2;j<=n;j++)
		f[i][j]=(f[i][j-i*(i+1)/2]+f[i-1][j-i])%mod,(res+=f[i][j])%=mod;
}
int main(){
	scanf("%d%d",&n,&m);
	if(m>=4)dfs(min(n,21)),printf("%d\n",res);
	if(m==3)dfs(min(n,63)),printf("%d\n",res); 
	if(m==1)solve1(),printf("%d\n",res);
	if(m==2)solve2(),printf("%d\n",res);
//	if(m==3)solve3(),printf("%d\n",res);
	return 0;
}