# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 105;
const int MAXM = 27;
void solve(int, int, int);
int qry(int, int);
void asw(int*);
int n, m, k, p0, nm, tol, pre;
int p[MAXN];
vector <int> s;
bool flag[MAXN];
int qry(int u, int v){
	printf("? %d %d\n", u, v);
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	return ans;
}
void asw(int arr[]){
	printf("! ");
	for (int i = 1; i < n; i++) printf("%d ", arr[i]);
	putchar('\n');
	fflush(stdout);
}
int md(int x){
	return (x % tol + tol) % tol;
}
int myqry(int u, int v){
	p[u] = ((p[u] + v) % tol + tol) % tol;
	int w = qry(u, v);
	int tmp = w - nm;
	nm = w;
	// printf("tmp %d\n", tmp);
	return tmp;
}
void mv(int u, int v){
	for (int i = 1; i <= abs(v); i++) myqry(u, v / abs(v));
}
bool check(){
	int ans = myqry(0, -1);
	myqry(0, 1);
	return ans != -1;
}
int fd(){
	for (int i = 0; i < s.size(); i++){
		myqry(s[i], -1);
		if (check()) return i;
	}
	assert(false);
	return -1;
}
void solve(int n, int m, int k){
	// freopen("1.out", "w", stdout);
	tol = n * m;
	for (int i = 1; i < n; i++) s.push_back(i);
	myqry(0, 1);
	for (int i = 1; i < n; i++){
		int pre = myqry(0, 1);
		while (true){
			int na = myqry(0, 1);
			if (pre == 1 && na != 1) break;
			pre = na;
		}
		myqry(0, -1);
		int nw = fd();
		p[s[nw]] = md(p[0] - 1);
		flag[s[nw]] = true;
		mv(s[nw], -m);
		s.erase(s.begin() + nw);
		myqry(0, -1);
	}
	for (int i = 1; i < n; i++){
		assert(flag[i]);
		p[i] = md(p[i] - p[0]);
	}
	asw(p);
}
int main(){
	scanf("%d%d", &n, &m);
	solve(n, m, k);
	return 0;
}