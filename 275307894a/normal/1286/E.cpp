#include<bits/stdc++.h>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (600000+5)
#define M ((N<<2)+5)
#define K (1500+5)
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-5)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;const int Mx=(1<<30)-1;map<int,int> F;
int n,m,k,x,y,z,Nt[N],Pr[N][26],W[N],st[N],H;char S[N],c;__int128 Ans,Ts;
I int Qry(int x){return W[*LB(st+1,st+H+1,x)];}
I void print(__int128 x){x>9&&(print(x/10),0);Pc(x%10+48);}
int main(){
	//freopen("1.in","r",stdin);
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++){
		c=Gc();while(c<'a'||c>'z') c=Gc();c=(c-97+Ans)%26+97;scanf("%d",&W[i]);W[i]^=Ans&Mx;S[i]=c;Nt[i]=Nt[i-1];if(i^1){ while(Nt[i]&&S[Nt[i]+1]^c) Nt[i]=Nt[Nt[i]];S[Nt[i]+1]==c&&(Nt[i]++);}
		if(i)Mc(Pr[i-1],Pr[Nt[i-1]]),Pr[i-1][S[Nt[i-1]+1]-'a']=Nt[i-1];if(S[i]==S[1]) F[W[i]]++,Ts+=W[i];
		int x=i-1;while(x){int Mx=0;for(int j=0;j<26;j++) j^(c-'a')&&(Mx=max(Mx,Pr[x][j]));x=Mx;x&&(Ts-=Qry(i-x),F[Qry(i-x)]--);}while(H&&W[st[H]]>W[i]) H--;st[++H]=i;
		while(!F.empty()){auto Ps=*F.rbegin();if(Ps.first<=W[i]) break;F[W[i]]+=Ps.second;Ts-=1ll*(Ps.first-W[i])*Ps.second;F.erase(Ps.first);}Ans+=Ts;print(Ans);Pc('\n');
	}
}