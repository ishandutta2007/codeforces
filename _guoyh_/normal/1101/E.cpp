# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 500051;
const int MR = 1000000051;
struct Tree{
	int nm, tag;
	int ls, rs;
} t[NR * 30];
int n, tsz;
void push_down(int nw){
	if (!t[nw].ls) t[nw].ls = ++tsz;
	if (!t[nw].rs) t[nw].rs = ++tsz;
	t[t[nw].ls].nm = max(t[t[nw].ls].nm, t[nw].tag);
	t[t[nw].rs].nm = max(t[t[nw].rs].nm, t[nw].tag);
	t[t[nw].ls].tag = max(t[t[nw].ls].tag, t[nw].tag);
	t[t[nw].rs].tag = max(t[t[nw].rs].tag, t[nw].tag);
	t[nw].tag = 0;
}
void update(int nw){
	t[nw].nm = max(t[t[nw].ls].nm, t[t[nw].rs].nm);
}
void modify(int nw, int lft, int rgt, int l, int r, int nm){
	if (l > r) return;
	if (lft == rgt){
		t[nw].nm = max(t[nw].nm, nm);
		t[nw].tag = max(t[nw].tag, nm);
		return;
	}
	push_down(nw);
	int mid = (lft + rgt) >> 1;
	if (l <= mid) modify(t[nw].ls, lft, mid, l, min(r, mid), nm);
	if (r >= mid + 1) modify(t[nw].rs, mid + 1, rgt, max(l, mid + 1), r, nm);
	update(nw);
}
int getmx(int nw, int lft, int rgt, int pos){
	if (lft == rgt) return t[nw].nm;
	push_down(nw);
	int mid = (lft + rgt) >> 1;
	if (pos <= mid) return getmx(t[nw].ls, lft, mid, pos);
	else return getmx(t[nw].rs, mid + 1, rgt, pos);
}
int main(){
	scanf("%d", &n);
	int rt = ++tsz;
	int mix = 1, miy = 0;
	while (n--){
		char op;
		int x, y;
		scanf(" %c", &op);
		scanf("%d%d", &x, &y);
		if (x > y) swap(x, y);
		if (op == '+'){
			mix = max(mix, x);
			miy = max(miy, y);
		} else {
			if (x < mix || y < miy){
				printf("NO\n");
				continue;
			} else printf("YES\n");
		}
	}
	return 0;
}