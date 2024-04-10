#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define y1 y12
#define y2 y21
using namespace std;

int T;
int a, b, c, d;
int x, y, x1, y1, x2, y2;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		scanf("%d%d%d%d%d%d", &x, &y, &x1, &y1, &x2, &y2);
		int hor = b - a, ver = d - c;
		if(((a == 0 && b == 0) || x2 - x1 > 0) && ((c == 0 && d == 0) || y2 - y1 > 0) && 
		   x1 <= x + hor && x + hor <= x2 && y1 <= y + ver && y + ver <= y2) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}