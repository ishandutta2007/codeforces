#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
struct node{
	int x1, y1, x2, y2;
	void init(){ x1 = read(), y1 = read(), x2 = read(), y2 = read(); }
	bool cover(node rhs){
		return x1 <= rhs.x1 && y1 <= rhs.y1 && x2 >= rhs.x2 && y2 >= rhs.y2;
	}
	bool coverx(node rhs){
		return x1 <= rhs.x1 && x2 >= rhs.x2;
	}
	bool covery(node rhs){
		return y1 <= rhs.y1 && y2 >= rhs.y2;
	}
	node mergex(node rhs){
		node res = *this;
		res.x1 = std :: min(x1, rhs.x1), res.x2 = std :: max(x2, rhs.x2);
		return res;
	}
	node mergey(node rhs){
		node res = *this;
		res.y1 = std :: min(y1, rhs.y1), res.y2 = std :: max(y2, rhs.y2);
		return res;
	}
}A, B, C;
int main(){
	A.init(), B.init(), C.init();
	if (B.cover(A) || C.cover(A)) return puts("NO"), 0;
	if (B.coverx(A) && C.coverx(A) && B.y2 >= C.y1 && C.y2 >= B.y1 && B.mergey(C).cover(A)) return puts("NO"), 0;
	if (B.covery(A) && C.covery(A) && B.x2 >= C.x1 && C.x2 >= B.x1 && B.mergex(C).cover(A)) return puts("NO"), 0;
	puts("YES");
}