#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 1005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct Point{
	int x,y;
	Point(int x = 0,int y = 0): x(x),y(y) {}
	Point operator + (Point p){
		return Point(x + p.x,y + p.y);
	}
	Point operator - (Point p){
		return Point(x - p.x,y - p.y);
	}
	Point operator - (){
		return Point(-x,-y);
	}
	bool operator == (const Point &p)const
	{
		return x == p.x && y == p.y;
	}
	bool operator < (const Point &p)const
	{
		if(x == p.x) return y < p.y;
		else return x < p.x;
	}

	void print(){
		printf("%d %d\n",x,y);
	}

};
typedef Point Vector;
int n;
Point obe[maxn],clu[maxn];
bool used[maxn];
bool check(Point tre){
	memset(used,0,sizeof(used));
	for(int i=1;i<=n;i++){
		int pos = lower_bound(clu + 1,clu + n + 1,tre - obe[i]) - clu;
		if(clu[pos] == tre - obe[i] && !used[pos]) used[pos] = true;
		else return false;
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&obe[i].x,&obe[i].y);
	for(int i=1;i<=n;i++) scanf("%d%d",&clu[i].x,&clu[i].y);
	sort(clu + 1,clu + n + 1);
	for(int i=1;i<=n;i++){
		if(check(obe[1] + clu[i])){
			(obe[1] + clu[i]).print();
			return 0;
		}
	}
	return 0;
}