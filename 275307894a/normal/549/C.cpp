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
using namespace std;const int N=200+5,M=6000+5,K=(1<<16)+5,mod=998244353,M1=998244353,M2=1e9+7,Mod=mod-1;const db eps=1e-5;
int n,m,x,C1,C2;
int main(){
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	int i,j;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) scanf("%d",&x),x&1?C1++:C2++;
	if(n==m){puts(C1&1?"Stannis":"Daenerys");return 0;}
	if((n-m)/2>=C1){puts("Daenerys");return 0;}if((n-m+1)/2>=C2&&m&1) {puts("Stannis");return 0;}
	else if((n-m)/2>=C2&&!(m&1)){puts("Daenerys");return 0;}
	if((n&1)^(m&1)) puts("Stannis");else puts("Daenerys"); 
}