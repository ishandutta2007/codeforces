#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (200000+5)
#define M ((1<<16)+5)
#define K (1000+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
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
int n,m,k,l,r,mid,x,Ans;
int main(){
	int i,j;scanf("%d",&n);l=0;r=5000000;while(l+1<r) mid=l+r>>1,cout<<"? "<<mid<<endl,cin>>x,(x^1?l:r)=mid;
	Ans=r;for(i=2;i<=n;i++) cout<<"? "<<(r-1)/i<<endl,cin>>x,x&&(Ans=min(Ans,x*((r-1)/i)));cout<<"! "<<Ans<<endl;
}