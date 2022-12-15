#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

const int inf=1e9;

int n;
int fl[2001],tar[2001],cache[2012][10001];

int _abs(int a) {
	return a<0 ? -a : a;
}

int DP(int idx,int s) {
	int &ret=cache[idx][s];
	if(ret!=-1) return ret;

	if(idx==1) ret=0;
	else ret=1;

	int cur=fl[idx-1];
	vector<int> tpos;

	while(s!=0) {
		tpos.push_back(s%10);
		s/=10;
	}
	reverse(tpos.begin(),tpos.end());
	if(idx==n+1) {
		if(tpos.size()==1) {
			ret += _abs(cur-tpos[0]);
		}	
		else {
			ret += min(_abs(cur-tpos[0])+_abs(tpos[0]-tpos.back()),
						_abs(cur-tpos.back()) + _abs(tpos.back()-tpos[0]));
		}

		ret += (int)tpos.size();

		return ret;
	}
	else {
		int mx = inf;
		int nxt=fl[idx],tv=tar[idx];
		for(int t=0;t<(1<<((int)tpos.size()));t++) {
			vector<int> use, rem;
			int f=0;
			for(int j=0;j<(int)tpos.size();j++) {
				if(t>>j & 1) use.push_back(tpos[j]);
				else {
					if(!f && tv <= tpos[j]) {
						rem.push_back(tv);
						f=1;
					}
					rem.push_back(tpos[j]);
				}
			}
			if(!f) rem.push_back(tv);

			if((int)rem.size()>4) continue;

			int nx_val=0,v=0;
			for(int j=0;j<(int)rem.size();j++) nx_val=nx_val*10+rem[j];
			v=DP(idx+1,nx_val);

			if(use.size()==0){
				v+= _abs(cur-nxt);
			}
			else if(use.size()==1) {
				v += _abs(cur-use[0]) + _abs(use[0]-nxt);
			}
			else {
				v += min(_abs(cur-use[0])+_abs(use[0]-use.back())+_abs(use.back()-nxt),
						_abs(cur-use.back())+_abs(use.back()-use[0])+_abs(use[0]-nxt));
			}
			v += (int)use.size();
			
			mx=min(mx, v);
		}
		ret += mx;
		return ret;
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",fl+i,tar+i);
	}
	fl[0] = 1;
	
	memset(cache,-1,sizeof(cache));

	printf("%d\n",DP(1,0));
	
	return 0;
}