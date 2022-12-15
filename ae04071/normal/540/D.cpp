#include <bits/stdc++.h>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;

struct data{
	double a[3];
};
data cache[101][101][101];

data DP(int a,int b,int c) {
	data &ret=cache[a][b][c];
	if(ret.a[0]>-0.5) return ret;
	
	for(int i=0;i<3;i++) ret.a[i]=0;
	if(a==0 && b==0) {
		ret.a[2]=1; return ret;
	} else if(a==0 && c==0) {
		ret.a[1]=1; return ret;
	} else if(b==0 && c==0) {
		ret.a[0]=1; return ret;
	}

	int as=a*b, bs=b*c, cs=c*a, sum=as+bs+cs;
	
	if(b) {
	data t=DP(a,b-1,c);
	for(int i=0;i<3;i++) ret.a[i] += t.a[i] * (double)as / sum;
	}
	
	if(c) {
	data t=DP(a,b,c-1);
	for(int i=0;i<3;i++) ret.a[i] += t.a[i] * (double)bs / sum;
	}
	
	if(a) {
	data t=DP(a-1,b,c);
	for(int i=0;i<3;i++) ret.a[i] += t.a[i] * (double)cs / sum;
	}

	return ret;
}
int main() {
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);

	for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) for(int k=0;k<=c;k++) {
		for(int t=0;t<3;t++) cache[i][j][k].a[t]=-1;
	}
	
	data res=DP(a,b,c);
	for(int i=0;i<3;i++) printf("%.10lf ",res.a[i]);
	
	return 0;
}