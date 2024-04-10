#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,r,c;
char str[200100];
pii lp[200100],rp[200100];
const int dy[]={-1,1,0,0},dx[]={0,0,-1,1};
int get(char ch) {
	switch(ch) {
		case 'U': return 1;
		case 'D': return 0;
		case 'L': return 2;
		case 'R': return 3;
		default:
			assert(false);
			return -1;
	}
}
void init() {
	int y=0,x=0;
	for(int i=1;i<=n;i++) {
		y+=dy[get(str[i-1])]; x+=dx[get(str[i-1])];
		lp[i] = pii(y,x);
	}
	rp[n]=pii(r,c);
	y=r; x=c;
	for(int i=n-1;i>=0;i--) {
		y-=dy[get(str[i])]; x-=dx[get(str[i])];
		rp[i] = pii(y,x);	
	}
}

inline int _abs(int a) {
	return a<0 ? -a : a;
}
bool check(int l) {
	for(int i=0;i+l<=n;i++) {
		long long v=1ll*abs(lp[i].first-rp[i+l].first)+_abs(lp[i].second-rp[i+l].second);
		if(v<=l && (l-v)%2==0) return true;
	}
	return false;
}

int main() {
	scanf("%d%s%d%d",&n,str,&c,&r);
	init();

	int lo=-1,up=n+1;
	while(up-lo>1) {
		int md=(lo+up)>>1;
		if(check(md)) up=md;
		else lo=md;
	}
	if(up==n+1) up=-1;
	printf("%d\n",up);
	return 0;
}