#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define mp make_pair
#define maxn 105
using namespace std;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
typedef long long ll;
typedef pair<int,int> P;
int n,a[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0] = 0;
	a[n + 1] = 1001;
	int len = 1,ans = 0;
	for(int i=1;i<=n + 1;i++){
		if(a[i] == a[i - 1] + 1){
			len++;
		}else{
			ans = max(ans,len - 2);
			len = 1;
		}
	}
	ans = max(ans,len - 2);
	printf("%d\n",ans);
	return 0;
}