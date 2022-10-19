#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define lb long db
#define N 10000
#define K 400
#define mod 20170408
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar()
#define Pc(x) putchar(x) 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*(x-1)+(y))
using namespace std;
int n,k;ll ToT,A[N+5];
I ll Query(int x,int y){ll F1=0,F2=0;cout<<"or"<<" "<<x<<" "<<y<<endl;cin>>F1;cout<<"and"<<" "<<x<<" "<<y<<endl;cin>>F2;return F1+F2;}
int main(){
	re int i;scanf("%d%d",&n,&k);A[1]=Query(2,3);A[2]=Query(1,3);A[3]=Query(1,2);
	ToT=A[1]+A[2]+A[3];ToT>>=1;A[1]=ToT-A[1];A[2]=ToT-A[2];A[3]=ToT-A[3];
	for(i=4;i<=n;i++)A[i]=Query(1,i)-A[1];sort(A+1,A+n+1);cout<<"finish"<<" "<<A[k]<<endl;
}