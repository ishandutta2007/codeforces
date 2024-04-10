#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int maxx,maxy;
char fl[3];
int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%s",fl);
		if(fl[0] == '+'){
			int x,y;
			scanf("%d%d",&x,&y);
			if(x > y) swap(x,y);
			maxx = max(maxx,x);
			maxy = max(maxy,y);
		}else{
			int h,w;
			scanf("%d%d",&h,&w);
			if(h > w) swap(h,w);
			if(maxx <= h && maxy <= w) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}