#include<bits/stdc++.h>
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using ll=long long;using db=double;using lb=long db;using ui=unsigned;using ull=unsigned ll;
using namespace std;const int N=200000+5,M=6000+5,K=(1<<16)+5,mod=998244353,M1=998244353,M2=1e9+7,Mod=mod-1;const db eps=1e-5;
int n,m,k,x,y,z,Q1[N],Q2[N],B[N],C[N],Bh,Ch,Q[N];ll Ans;vector<int> Id[N];char s[N];unordered_map<int,int> f;
int main(){
	//freopen("1.in","r",stdin);
	int i,j;scanf("%s",s+1);n=strlen(s+1);k=sqrt(n)*3+1;for(i=1;i<=n;i++) Q1[i]=Q1[i-1]+(s[i]=='0'),Q2[i]=Q2[i-1]+(s[i]=='1');
	for(i=1;i<=n;i++) {
		if(s[i]=='0') B[++Bh]=i;else C[++Ch]=i;x=i;
		for(j=Ch;j&&j>Ch-k;j--) Ans+=(Q1[i]-Q1[C[j-1]])/(Ch-j+1)-(Q1[i]-Q1[C[j]])/(Ch-j+1)+((Q1[i]-Q1[C[j]])%(Ch-j+1)==0),x=C[j-1];Id[x].PB(i);
	}
	for(i=0;i<=n/k+1;i++){
		for(j=1;j<=n;j++) Q[j]=Q[j-1]+(s[j]=='0'?-1:i);f.clear();
		for(j=1;j<=n;j++){
			f[Q[j-1]]++;for(int h:Id[j]) Ans+=f[Q[h]];
		}
	}printf("%lld\n",Ans);
}