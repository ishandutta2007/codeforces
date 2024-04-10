# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ld, ld> pdd;
# define fi first
# define se second
const int MAXN = 100053;
int n;
ll t;
struct Node{
	ll a, b;
	ld p;
} a[MAXN];
ld mxw;
int st[MAXN], tp;
pdd getl(int i){
	return pdd(a[i].p, a[i].p * a[i].a);
}
bool check(int i1, int i2, int i3){ //l1*l3 <= l1*l2
	pdd l1 = getl(i1), l2 = getl(i2), l3 = getl(i3);
	return (l1.se - l3.se) * (l2.fi - l1.fi) <= (l1.se - l2.se) * (l3.fi - l1.fi);
}
struct Matrix{
	int ax, ay;
	ld a[3][3];
	Matrix(int ax = 0, int ay = 0): ax(ax), ay(ay){
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++) a[i][j] = 0;
		}
	}
	void prt(){
		for (int i = 0; i < ax; i++){
			for (int j = 0; j < ay; j++){
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
};
Matrix operator * (const Matrix &u, const Matrix &v){
	Matrix ans = Matrix(u.ax, v.ay);
	for (int i = 0; i < ans.ax; i++){
		for (int k = 0; k < u.ay; k++){
			for (int j = 0; j < ans.ay; j++){
				ans.a[i][j] += u.a[i][k] * v.a[k][j];
			}
		}
	}
	return ans;
}
Matrix F1[MAXN];
Matrix F[35];
int main(){
	cin >> n >> t;
	for (int i = 1; i <= n; i++){
		cin >> a[i].a >> a[i].b >> a[i].p;
		mxw = max(mxw, a[i].b * a[i].p);
	}
	sort(a + 1, a + n + 1, [](Node u, Node v){
		return u.p < v.p;
	});
	for (int i = 1; i <= n; i++){
		while (tp >= 2 && check(st[tp - 1], st[tp], i)) tp--;
		st[++tp] = i;
	}
	for (int i = 1; i <= tp; i++){
		F1[i] = Matrix(3, 3);
		F1[i].a[0][0] = 1 - a[st[i]].p;
		F1[i].a[1][0] = a[st[i]].p * mxw;
		F1[i].a[2][0] = a[st[i]].p * a[st[i]].a;
		F1[i].a[1][1] = F1[i].a[2][1] = F1[i].a[2][2] = 1;
		// cout << "st " << i << ' '  << getl(st[i]).fi << ' ' << getl(st[i]).se << '\n';
		// F1[i].prt();
	}
	Matrix ans = Matrix(1, 3);
	ans.a[0][2] = 1;
	for (int i = 1; i <= tp; i++){
		F[0] = F1[i];
		for (int j = 1; j <= 34; j++) F[j] = F[j - 1] * F[j - 1];
		for (int j = 34; j >= 0; j--){
			if (t >= (1ll << j) && (ans * F[j] * F1[i]).a[0][0] > (ans * F[j] * F1[i + 1]).a[0][0]){
				ans = ans * F[j];
				t -= (1ll << j);
				// cout << "?\n";
			}
		}
		if (t >= 1 && (ans * F1[i]).a[0][0] > (ans * F1[i + 1]).a[0][0]){
			ans = ans * F1[i];
			// cout << "??\n";
			t--;
		}
		// ans.prt();
		// cout << "t " << i << ' ' << t << '\n';
	}
	// cout << ans.a[0][0] << '\n';
	cout << fixed << setprecision(10) << ans.a[0][0] << '\n';
	return 0;
}