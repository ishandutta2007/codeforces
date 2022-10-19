#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (3000+5)
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
int l,r,mid,cnt,T,n,x,Fl[N];
I void Solve(){
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) Fl[i]=0;
	for(i=n-1;i;i--){
		cout<<"? 1 "<<n-i<<endl;cout<<i<<endl;for(j=i+1;j<=n;j++) cout<<j<<" ";cout<<endl;
		cin>>x;if(x) break;
	}Fl[i]=1;
	for(j=i-1;j;j--) cout<<"? 1 1"<<endl<<i<<endl<<j<<endl,cin>>Fl[j];
	l=i;r=n+1;while(l+1<r){mid=l+r>>1;cout<<"? "<<1<<" "<<n-mid+1<<endl;
		cout<<i<<endl;for(j=mid;j<=n;j++) cout<<j<<" ";cout<<endl;cin>>x;
		(x?l:r)=mid;
	} Fl[l]=1;cnt=0;for(j=1;j<=n;j++) cnt+=(!Fl[j]);cout<<"! "<<cnt<<" ";for(j=1;j<=n;j++) !Fl[j]&&(cout<<j<<" ");cout<<endl;
}
int main(){
	scanf("%d",&T);while(T--) Solve();
}