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
int n,h,x1[maxn],x2[maxn],dif[maxn];
int main(){
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;i++) scanf("%d%d",&x1[i],&x2[i]);
	for(int i=1;i<n;i++) dif[i + 1] = x1[i + 1] - x2[i];
	for(int i=1;i<n;i++) dif[i + 1] += dif[i];
	int ans = 0;
	for(int i=1;i<=n;i++){
		int lb = i,rb = n;
		while(lb < rb){
			int mid = (lb + rb + 1) >> 1;
			if(dif[mid] - dif[i] < h) lb = mid;
			else rb = mid - 1;
		}
		int rh = h - (dif[lb] - dif[i]);
		ans = max(ans,x2[lb] - x1[i] + rh);
	}
	printf("%d\n",ans);
	return 0;
}