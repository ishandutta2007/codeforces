#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 30
#define K 50
#define mod 1000000007
#define eps (1e-9)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using namespace std;
int T,n,m,k,flag,x,y,z,nowx,nowy,Fl;string a,B[N+5]={"Right", "Left", "Up", "Down", "Down-Right", "Down-Left", "Up-Left", "Up-Right","Done"};
I int Y(string a){return (a==B[0])||(a==B[1])||(a==B[4])||(a==B[5])||(a==B[6])||(a==B[7]);}
I int X(string a){return (a==B[2])||(a==B[3])||(a==B[4])||(a==B[5])||(a==B[6])||(a==B[7]);}
I void Over(string a){if(a==B[8])Fl=1;}
I void Out(){cout<<nowx<<" "<<nowy<<endl;}
I void push(){
	flag=0;while(!flag){
		cin>>a;Over(a);if(Fl) return;if(X(a)){
			if(nowx==8) {nowx--;flag=1;}else nowx++;
		}
		if(Y(a)){
			if(nowy==8) {nowy--;flag=1;}else nowy++;
		}Out();
	}
	flag=0;while(!flag){
		cin>>a;Over(a);if(Fl) return;if(X(a)){
			if(nowx==1) {nowx++;flag=1;}else nowx--;
		}
		if(Y(a)){
			if(nowy==8) {nowy--;flag=1;}else nowy++;
		}Out();
	}
	flag=0;while(!flag){
		cin>>a;Over(a);if(Fl) return;if(X(a)){
			if(nowx==1) {nowx++;flag=1;}else nowx--;
		}
		if(Y(a)){
			if(nowy==1) {nowy++;flag=1;}else nowy--;
		}Out();
	}
	flag=0;while(!flag){
		cin>>a;Over(a);if(Fl) return;if(X(a)){
			if(nowx==8) {nowx--;flag=1;}else nowx++;
		}
		if(Y(a)){
			if(nowy==1) {nowy++;flag=1;}else nowy--;
		}Out();
	}
}
int main(){
	scanf("%d",&T);while(T--){
		Fl=0;printf("%d %d\n",nowx=4,nowy=4);fflush(stdout);
	    push();if(Fl) continue;cin>>a;Over(a);if(Fl) continue;if(!X(a)) {if(nowx==8)nowx--;else nowx++;}if(Y(a)){if(nowy==8) nowy--;else nowy++;}if(X(a)&&!Y(a)){if(nowx>=7) nowx-=2;else nowx+=2;}Out();
	    push();if(Fl) continue;cin>>a;Over(a);if(Fl) continue;if(X(a)) {if(nowx==8)nowx--;else nowx++;}if(!Y(a)){if(nowy==8) nowy--;else nowy++;}if(!X(a)&&Y(a)){if(nowx>=7) nowx-=2;else nowx+=2;}Out();
	    push();if(Fl) continue;cin>>a;Over(a);if(Fl) continue;if(!X(a)) {if(nowx==8)nowx--;else nowx++;}if(Y(a)){if(nowy==8) nowy--;else nowy++;}if(X(a)&&!Y(a)){if(nowx>=7) nowx-=2;else nowx+=2;}Out();push();if(Fl) continue;
	}
}