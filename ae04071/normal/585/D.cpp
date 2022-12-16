#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long lli;
typedef pair<int,int> pii;

const int BOUND=13;

map<pii,pii> tr;
int n,v[25][3];

int power(int a,int p) {
	int res=1; 
	while(p--) res=res*a; 
	return res;
}
void print_ans(int val) {
	if(val==0) puts("MW");
	else if(val==1) puts("LW");
	else puts("LM");
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) for(int j=0;j<3;j++) scanf("%d",&v[i][j]);

	if(n<=BOUND) {
		int CV=power(3,n),as=-1,gv=-1;
		for(int s=0;s<CV;s++) {
			int ts=s,tv[3]={0,};
			for(int i=0;i<n;i++) {
				for(int j=0;j<3;j++) if(ts%3!=j) tv[j] += v[i][j];
				ts/=3;
			}
			if(tv[0]==tv[1] && tv[1]==tv[2]) {
				if(as==-1 || gv < tv[0]) {
					as=s;
					gv=tv[0];
				}
			}
		}
		if(as==-1) puts("Impossible");
		else {
			for(int i=0;i<n;i++) {
				print_ans(as%3);
				as/=3;
			}
		}
	} else {
		int CV=power(3,BOUND);
		for(int s=0;s<CV;s++) {
			int ts=s,tv[3]={0,};
			for(int i=0;i<BOUND;i++) {
				for(int j=0;j<3;j++) if(ts%3!=j) tv[j] += v[i][j];
				ts/=3;
			}
			pii kv(tv[0]-tv[1],tv[1]-tv[2]);
			if(tr.count(kv)) {
				if(tr[kv].se < tv[0]) {
					tr[kv] = pii(s, tv[0]);
				}
			} else {
				tr[kv] = pii(s, tv[0]);
			}
		}
		
		int as1=-1, as2, gv=-1e9;
		CV = power(3,n-BOUND);
		for(int s=0;s<CV;s++) {
			int ts=s,tv[3]={0,};
			for(int i=0;i<n-BOUND;i++) {
				for(int j=0;j<3;j++) if(ts%3!=j) tv[j] += v[i+BOUND][j];
				ts/=3;
			}
			
			pii kv(tv[1]-tv[0], tv[2]-tv[1]);
			if(tr.count(kv)) {
				if(as1==-1 || gv < tv[0]+tr[kv].se) {
					as1=tr[kv].fi; as2=s; gv=tv[0]+tr[kv].se;
				}
			}
		}
		if(as1==-1) puts("Impossible");
		else {
			for(int i=0;i<BOUND;i++) {
				print_ans(as1%3);
				as1/=3;
			}
			for(int i=0;i<n-BOUND;i++) {
				print_ans(as2%3);
				as2/=3;
			}
		}
	}

	return 0;
}