#include<stdio.h>
#include<algorithm>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
int n,k,l,T;
il int Max(ct p,ct q){return p>q?p:q;}
int main(){
	scanf("%d",&T);it x;
	while(T--){
		scanf("%d%d%d",&n,&k,&l);it fl=1,lst=0;
		for(it i=1;i<=n;++i){
			scanf("%d",&x);
			if(x>l) fl=0;
			if(x+k<=l) lst=0;
			else if(lst<k) lst=Max(lst+1,k-(l-x));
			else (k+(l-x)<lst+1)?fl=0:++lst;
		}
		fl?puts("Yes"):puts("No");
	}
	return 0;
}