#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

inline lli _abs(lli a) {return a<0 ? -a : a;}
inline int _abs(int a) {return a<0 ? -a : a;}

int ps[26];
int main() {
	int n,a;
	scanf("%d",&n);

ps[1]=0;
ps[2]=1;
ps[3]=1;
ps[4]=5;
ps[5]=1;
ps[6]=21;
ps[7]=1;
ps[8]=85;
ps[9]=73;
ps[10]=341;
ps[11]=89;
ps[12]=1365;
ps[13]=1;
ps[14]=5461;
ps[15]=4681;
ps[16]=21845;
ps[17]=1;
ps[18]=87381;
ps[19]=1;
ps[20]=349525;
ps[21]=299593;
ps[22]=1398101;
ps[23]=178481;
ps[24]=5592405;
ps[25]=1082401;
		
	while(n--) {
		scanf("%d",&a);
		
		int c=1,cnt=0;
		for(;(c-1)<a;c<<=1,cnt++);
		c--;
		if(c==a) {
			printf("%d\n",ps[cnt]);
		}else {
			printf("%d\n",c);
		}
	}
	return 0;
}