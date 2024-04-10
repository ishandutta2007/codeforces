#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (2500+5)
#define M (N-5)
#define K (1500+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
#include <vector>
using namespace std;
int n,A[N],m,Ans,La,x;string a,b;
struct Ques{int w,id;}S[N];I bool cmp(Ques x,Ques y){return x.w<y.w;}
int main(){
	int i,j;scanf("%d%d",&n,&m);for(i=0;i<m;i++) a+="0";
	for(i=0;i<m;i++) {
		b=a;b[i]='1';cout<<"? "<<b<<endl;cin>>S[i].w;S[i].id=i;
	}sort(S,S+m,cmp);b=a;
	for(i=0;i<m;i++){
		b[S[i].id]='1';cout<<"? "<<b<<endl;cin>>x;if(x==La+S[i].w) La+=S[i].w;else b[S[i].id]='0';
	}cout<<"! "<<La<<endl;
}//