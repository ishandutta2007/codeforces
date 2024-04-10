#include<bits/stdc++.h>
#define ll long long
#define N 400015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int a,b,k,x[N],y[N];
void fck(int Mn){
	rep(i,1,b){
		if(!Mn) break;
		if(y[i]) continue;
		printf("1");
		y[i]=1;Mn--;
	}
	rep(i,1,a){
		if(!Mn) break;
		if(x[i]) continue;
		printf("0");
		x[i]=1;Mn--;
	}
}
void cs1(){
	puts("Yes");
	rep(i,1,b) printf("1");
	rep(i,1,a) printf("0");
	printf("\n");
	rep(i,1,b) printf("1");
	rep(i,1,a) printf("0");
	printf("\n");
	exit(0);
}
void cs2(){
	b -= 2;a -= 1;
	puts("Yes");printf("11");
	fck(k-1);
	printf("0");
	fck(a+b-k+1);
	printf("\n");
	memset(x,0,sizeof x);
	memset(y,0,sizeof y);
	printf("10");
	fck(k-1);
	printf("1");
	fck(a+b-k+1);
}
int main(){
	scanf("%d%d%d",&a,&b,&k);
	if(k==0) cs1();
	if(a==0||b==1||k>(a+b-2)) return puts("No"),0;
	cs2();
    return 0;
}