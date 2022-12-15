#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <utility>
#include <queue>
#include <functional>

#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;

int n,k,arr[100001];
int main() {
	scanf("%d%d",&n,&k);
	
	int v=k;
	for(int i=0;i<n;i++) {
		if(v) {
			arr[i*2]=i*2+2; arr[2*i+1]=i*2+1;
			v--;
		} else {
			arr[i*2]=i*2+1; arr[2*i+1]=i*2+2;
		}
	}
	for(int i=0;i<n*2;i++) printf("%d ",arr[i]);

	return 0;
}