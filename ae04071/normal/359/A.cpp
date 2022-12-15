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

int n,m,arr[50][50];

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&arr[i][j]);

	int f=4;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(arr[i][j]) {
		if( (i==0 && j==0) || (i==0 && j==m-1) ||
			(i==n-1 && j==0) || (i==n-1 && j==m-1)) f=min(f,1);
		else if(i==0 || j==0 || i==n-1 || j==m-1) f=min(f,2);
	}
	printf("%d\n",f);

	
	return 0;
}