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
#include <complex>

#define inf 999999999
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-5

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

int n;
int v[maxn];

vector<int> arr[400];
int cnt[400][maxn];
unsigned char last[400][maxn];

pii change[800];

pii find(int id){
	int i = 0;
	while(arr[i].size() <= id){
		id -= arr[i].size();
		i++;
	}
	return pii(i,id);
}

int buck;

void print(){
}

main(){

	int q;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		scanf("%d",v+i);

	int sq = 400;

	buck = n/sq;
	if(n%sq) buck++;
	int t;
	int cur = 0;
	int lastAns = 0;
	int ch = 0;

	scanf("%d",&q);

	for(int i=0;i<q;i++){

		if(i%sq == 0){
			t = 0;
			cur++;
			if(i) for(int j=0;j<buck;j++)
				for(int k=0;k<arr[j].size();k++)
					v[t++] = arr[j][k];
			if(i) for(int j=0;j<buck;j++)
				arr[j].clear();
			for(int j=0;j<n;j++){
				arr[j/sq].pb(v[j]);
				if(last[j/sq][v[j]] != cur) cnt[j/sq][v[j]] = 0;
				cnt[j/sq][v[j]]++;
				last[j/sq][v[j]] = cur;
				debug("last %d %d = %d\n",j/sq,v[j],cur);
			}
			ch = 0;
			print();
		}

		scanf("%d",&t);

		if(t == 1){
			int l,r;
			scanf("%d%d",&l,&r);
			l = (l-1+lastAns)%n;
			r = (r-1+lastAns)%n;
			if(l > r)
				swap(l,r);
			pii A = find(l);
			pii B = find(r);
			debug("A = %d %d\n",A.first,A.second);
			debug("B = %d %d\n",B.first,B.second);
			int e = arr[B.first][B.second];
			change[ch++] = pii(B.first,-e);
			change[ch++] = pii(A.first,e);
			int u = B.second;
			while(u != arr[B.first].size()-1){
				swap(arr[B.first][u],arr[B.first][u+1]);
				u++;
			}
			arr[B.first].pop_back();
			arr[A.first].pb(e);
			u = arr[A.first].size()-1;
			while(u > A.second){
				swap(arr[A.first][u],arr[A.first][u-1]);
				u--;
			}
			print();
		}

		if(t == 2){
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			l = (l-1+lastAns)%n;
			r = (r-1+lastAns)%n;
			k = (k-1+lastAns)%n+1;
			if(l > r)
				swap(l,r);
			pii A = find(l);
			pii B = find(r);
			debug("A = %d %d\n",A.first,A.second);
			debug("B = %d %d\n",B.first,B.second);
			int ans = 0;
			if(A.first == B.first){
				for(int j=A.second;j<=B.second;j++)
					if(arr[A.first][j] == k)
						ans++;
				printf("%d\n",ans);
				lastAns = ans;
				continue;
			}
			for(int j=A.second;j<arr[A.first].size();j++)
				if(arr[A.first][j] == k)
					ans++;
			for(int j=0;j<=B.second;j++)
				if(arr[B.first][j] == k)
					ans++;
			for(int j=A.first+1;j<B.first;j++){
				debug("get %d\n",j);
				if(last[j][k] != cur) cnt[j][k] = 0;
				debug("cnt[%d][%d] = %d last %d\n",j,k,cnt[j][k],last[j][k]);
				ans += cnt[j][k];
			}
			for(int j=0;j<ch;j++)
				if(abs(change[j].second) == k && change[j].first > A.first && change[j].first < B.first){
					if(change[j].second > 0)
						ans++;
					else
						ans--;
				}
			printf("%d\n",ans);
			lastAns = ans;
		}

	}

}