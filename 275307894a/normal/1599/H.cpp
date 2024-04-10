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
#define N 100000
#define M 5
#define mod 1000000007
#define Mod 998244352
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
using namespace std;
int n,Ans1,Ans2,Ans3,Ans4,x,y,z,w,W=1e9,B1,B2,B3,B4;
I int Ask(int x,int y){printf("? %d %d\n",x,y);cout<<endl;scanf("%d",&w);return w;}
int main(){
	RI i;Ans1=Ask(1,1);Ans2=Ask(W,W);
	Ans3=Ask(1,W);if(Ans1<Ans3){
		x=(W-(Ans3-Ans1)+1)/2;B2=Ask(1,x);B1=Ans1-B2;
	}else{
		x=(Ans1-Ans3+1+W)/2;B2=Ask(1,x);B1=Ans1-B2;
	}
	B4=Ask(W,x);B3=Ans2-B4;printf("! %d %d %d %d\n",B2+1,B1+1,W-B4,W-B3);cout<<endl;
}