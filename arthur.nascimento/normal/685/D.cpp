#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf (1<<30)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define pdp pair<double,pii>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 100100
#define mod 1000000007

#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)

#define nxt fusrf
#define last iyef

typedef long long ll;
using namespace std;

struct ev {
	int x, y, t;
	ev(int x=0,int y=0,int t=0): x(x), y(y), t(t) {}
	int pos;
	bool operator<(ev comp)const{
		return x < comp.x;
	}
};


int cur[maxn];
//unordered_map<int,int> ans;
//unordered_map<int,int> last;

int ans[100100][303];
int last[100100][303];

map<int,int> foi;


ll resp[maxn];

int ret;
char ch;
int p;
inline int read(){
	ret = p = 0;
	ch = getchar();
	if(ch == '-') p = 1;
	else ret = ch-'0';
	while((ch=getchar()) >= '0')
		ret = 10*ret+ch-'0';
	if(p) return -ret;
	return ret;
}

bool comp(ev a,ev b){
	return a.y < b.y;
}

main(){

	int n,k;	
	//scanf("%d%d",&n,&k);
	n = read();
	k = read();
	
	vector<ev> v;
	vector<int> cy;

	for(int i=0;i<n;i++){
		int x,y;
		//scanf("%d%d",&x,&y);
		x = read();
		y = read();
		if(!foi[y]){
			cy.pb(y);
			foi[y] =1 ;
		}
		v.pb(ev(x,y,0));
		v.pb(ev(x+k,y,1));
	}

	sort(v.begin(), v.end(), comp);
	sort(cy.begin(), cy.end());

	int ptr = 0;

	for(int i=0;i<2*n;i++){
		while(cy[ptr]+k < v[i].y)
			ptr++;
		v[i].pos = ptr;
		//debug("%d -> %d ptr %d\n",v[i].y,cy[ptr],ptr);
	}	

	debug("ok\n");

	sort(v.begin(), v.end());

	for(int i=0;i<2*n;i++){

		int x = v[i].x, y = v[i].y, t = v[i].t;

		//debug("x %d y %d t %d\n",x,y,t);

		//if(x != last){
		//	for(int j=1;j<=k;j++)
		//		resp[j] += (ll) (x-last) * ans[j];
		//}

		if(t == 0){
			ptr = v[i].pos;
			for(int j=y;j<y+k;j++){
				while(cy[ptr]+k < j) ptr++;
			//	cur[ans[j]]--;
				resp[ans[ptr][j-cy[ptr]]] += (x-last[ptr][j-cy[ptr]]);
			//	debug("resp[%d] += %d\n",ans[j],x-last[j]);
				last[ptr][j-cy[ptr]] = x;
				ans[ptr][j-cy[ptr]]++; 
				//debug("ans[%d] = %d\n",j,ans[j]);
			//	cur[ans[j]]++;
			}
		}
		else {
			ptr = v[i].pos;
			for(int j=y;j<y+k;j++){
				//cur[ans[j]]--;
				while(cy[ptr]+k < j) ptr++;
				resp[ans[ptr][j-cy[ptr]]] += (x-last[ptr][j-cy[ptr]]);
				//debug("resp[%d] += %d\n",ans[j],x-last[j]);
				last[ptr][j-cy[ptr]] = x;
				ans[ptr][j-cy[ptr]]--;
				//debug("ans[%d] = %d\n",j,ans[j]);
				//cur[ans[j]]++;
			}
		}

	}

	for(int i=1;i<=n;i++)
		printf("%lld ",resp[i]);
	printf("\n");

}