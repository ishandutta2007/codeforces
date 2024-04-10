#include <bits/stdc++.h>

using namespace std;
const int inf = 100010010;
int mem[1010][1010][11][2];
char s[1010],t[1010];
int n , m , k;

int dp(int i,int j,int kk,bool on){
if( i==n||j==m ){
    if( kk==0 )return 0;
    else       return -inf;
}


if( mem[i][j][kk][on]!= -1 )return mem[i][j][kk][on];
if(kk==0){
        if(on)if( s[i]==t[j] )
    return mem[i][j][kk][on]=1+dp(i+1,j+1,kk,on);
    return mem[i][j][kk][on]=0;
}
int ret=-inf;

if( on ){
    if( s[i]==t[j] ){
        ret=max(ret,1+dp(i+1,j+1,kk,1));
        ret=max(ret,1+dp(i+1,j+1,kk,0));}
        ret=max(ret,dp(i,j+1,kk,0));
        ret=max(ret,dp(i+1,j,kk,0));
return mem[i][j][kk][on]=ret;
}

ret=max(ret,dp(i+1,j,kk,0));
ret=max(ret,dp(i,j+1,kk,0));

if( s[i]==t[j] ){
ret=max(ret,1+dp(i+1,j+1,kk-1,1));
ret=max(ret,1+dp(i+1,j+1,kk-1,0));
}
return mem[i][j][kk][on]=ret;
}

int main()
{
memset(mem,-1,sizeof mem);
scanf("%d %d %d",&n,&m,&k);
//cin>>n>>m>>k;
scanf("%s %s",s,t);
//cin>>s>>t;
printf("%d\n",dp(0,0,k,0));
//cout<<dp(0,0,k,0)<<endl;


    return 0;
}