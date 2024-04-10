#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <utility>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <ctype.h>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;

int n,arr[500000],ml[500000],mr[500000];
inline int _abs(int a) { return a<0 ? -a : a; }

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",arr+i);

	ml[0]=arr[0];
	for(int i=1;i<n;i++) ml[i] = min(ml[i-1],arr[i]);
	mr[n-1]=arr[n-1];
	for(int i=n-2;i>=0;i--) mr[i] = min(mr[i+1],arr[i]);

	lli sum=0,ans=-1e15;
	for(int i=0;i<n;i++) sum += abs(arr[i]);
	for(int i=0;i<n;i++) {
		lli val=sum - _abs(arr[i]),t=arr[i];
		if(i!=0) val-=_abs(ml[i-1]),t-=ml[i-1];
		if(i!=n-1) val-=_abs(mr[i+1]),t-=mr[i+1];

		ans=max(ans,val+t);
	}

	printf("%lld\n",ans);
	
	return 0;
}