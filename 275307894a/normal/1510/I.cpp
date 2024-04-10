#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define RI re int
#define ll long long
#define db double
#define lb long db
#define N (1000+5)
#define M (1<<23)+5
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-9)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,m,F[N+5],W=1e9+7;char S[N+5],C[N+5];db Ba=0.75,B,A;
I db Rd(){return rand()*1.0/RAND_MAX;}
int main(){
	RI i;srand((unsigned int)time(0));scanf("%d%d",&n,&m);while(m--){
		A=B=0;cin>>S+1;for(i=1;i<=n;i++) A+=pow(Ba,F[i])*(S[i]=='1'),B+=pow(Ba,F[i])*(S[i]=='0');
		cout<<(Rd()<=A/(A+B)?'1':'0')<<endl;cin>>C+1;for(i=1;i<=n;i++)F[i]+=(C[1]!=S[i]);
	}
}