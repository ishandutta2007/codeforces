#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 100
#define M 200000
#define mod 998244353
#define eps (1e-7)
#define U unsigned int
#define IT set<ques>::iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
int n,T,flag;char s[N+5];
int main(){
	re int i,j;scanf("%d",&T);while(T--){
		scanf("%s",s+1);n=strlen(s+1);printf("%s\n",((n&1)||s[1]==')'||s[n]=='(')?"NO":"YES");
	}
}