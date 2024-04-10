#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
#include<iostream>

using namespace std;
typedef long long ll;
int x,y;
int main(){
	ios::sync_with_stdio(false);
	scanf("%d%d",&x,&y);
	if(y == 0){
		puts("No");
		return 0;
	}else if(y == 1){
		if(x == 0) puts("Yes");
		else puts("No");
		return 0;
	}
	int z = y - 1;
	if(z > x || (x - z) & 1) puts("No");
	else puts("Yes");
	return 0;
}