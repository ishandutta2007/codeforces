// xtqqwq
#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;

int ask(int x,int y){
	printf("SCAN %d %d\n",x,y);
	fflush(stdout);
	return readint();
}

int answer(int x,int y){
	printf("DIG %d %d\n",x,y);
	fflush(stdout);
	return readint();
}

void solve(){
	n=readint(); m=readint();
	int t1=ask(1,1)+4;
	int t2=ask(1,m)-2*m+2;
	int sr=(t1+t2)/2,sc=(t1-t2)/2;
	int dc=ask(1,sc/2)-sr+2;
	int dr=ask(sr/2,1)-sc+2;
	int r1=(sr+dr)/2,r2=(sr-dr)/2;
	int c1=(sc+dc)/2,c2=(sc-dc)/2;
	if(!answer(r1,c1)){
		assert(answer(r1,c2));
		assert(answer(r2,c1));
	}
	else assert(answer(r2,c2));
}

int main(){
	int T=readint();
	while(T--) solve();
	return 0;
}