#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#include <set>
#define maxn 300005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int ans[maxn];
set <int> kni;
typedef set<int> :: iterator Ite;
int lis[maxn],k;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) kni.insert(i);
	while(m--){
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		Ite it = kni.lower_bound(l);
		k = 0;
		do{
			if(*it != x){
				ans[*it] = x;
				lis[++k] = *it;
			}
			it++;
		}while(it != kni.end() && *it <= r);
		for(int i=1;i<=k;i++) kni.erase(lis[i]);
	}
	for(int i=1;i<=n;i++) printf("%d%c",ans[i],i == n ? '\n' : ' ');
	return 0;
}