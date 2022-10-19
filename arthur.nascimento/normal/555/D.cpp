#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define inf 99999999999.
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 200200

using namespace std;

pii v[maxn];
int pos[maxn];

int s[maxn];

int n;

int nxt(int id,int dir,int l){
	if(dir == 1){
		int low = id, up = n-1;
		while(low != up){
			int mid = (low+up+1)/2;
			if(v[mid].first - v[id].first <= l)
				low = mid;
			else
				up = mid-1;
		}
		return low;
	}
	else {
			int low = id, up = 0;
			while(low != up){
				int mid = (low+up)/2;
				if(v[id].first - v[mid].first <= l)
					low = mid;
				else
					up = mid+1;
			}
			return low;
	}
}

main(){
	
	int q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i].first);
		v[i].second = i;
	}
	
	sort(v,v+n);
	
	for(int i=0;i<n;i++)
		pos[v[i].second] = i;
		
	while(q--){
			int a,l;
			scanf("%d%d",&a,&l), a--;
			a = pos[a];
			s[0] = a;
			int t = 1;
			int dir = 1;
			while(1){
				debug("a %d l %d\n",a,l);
				if(t >= 3){
					if(s[t-1] == s[t-2] && s[t-1] == s[t-3])
						break;
					if(s[t-1] == s[t-3])
						l %= 2*abs(v[s[t-1]].first-v[s[t-2]].first);
				}
				int b = nxt(a,dir,l);
				l -= abs(v[a].first - v[b].first);
				dir = -dir;
				a = b;
				s[t++] = a;
			}
			printf("%d\n",v[a].second+1);
	}

}