#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define mp make_pair
#define maxn 200005
using namespace std;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
typedef long long ll;
typedef pair<int,int> P;
int n,m,d;
struct node{
	int id,val;
	bool operator < (const node &b)const
	{
		return val < b.val;
	}
}a[maxn];
int minday,ans[maxn];
int main(){
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].val);
		a[i].id = i;
	}
	sort(a + 1,a + n + 1);
	int j = 1,lb,rb;
	for(int i=1;i<=n;i++){
		while(j <= n && a[j].val - a[i].val <= d) j++;
		if(j - i > minday){
			minday = j - i;
			lb = i,rb = j - 1;
		}
	}
	for(int i=lb;i<=rb;i++) ans[a[i].id] = i - lb + 1;
	for(int i=lb-1;i>=1;i--) ans[a[i].id] = ans[a[i + minday].id];
	for(int i=rb+1;i<=n;i++) ans[a[i].id] = ans[a[i - minday].id];
	printf("%d\n",minday);
	for(int i=1;i<=n;i++){
		printf("%d%c",ans[i],i==n?'\n':' ');
	}
	return 0;
}