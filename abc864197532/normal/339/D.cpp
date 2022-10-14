#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int find (int a) {
    int k = 0;
    while (a) {
        k++;
        a>>=1;
    }
    return k;
}

struct Seg {
	int l,r,m,sum;
	Seg* ch[2];
	Seg (int l, int r): l(l), r(r), m(l + r >> 1){
		sum = 0;
		if (r - l != 1) {
			ch[0] = new Seg(l,m);
			ch[1] = new Seg(m,r);
		}
	}
	void pull() {
	    if (find(r - l) % 2) sum = ch[0]->sum ^ ch[1]->sum;
	    else sum = ch[0]->sum | ch[1]-> sum;
	}
	void set(int p, int v) {
		if (r - l == 1) {
			sum = v;
		} else {
			if (p < m) {
				ch[0]->set(p,v); 
			} else {
				ch[1]->set(p,v);
			}
			pull();
		}
	}
	int query() {
		return sum;
	}
};


int main () {
	int n,t,tmp;
	cin >> n >> t;
	Seg a (0,1 << n);
	fop (i,0,1 << n) {
		cin >> tmp;
		a.set(i,tmp);
	}
	while (t--) {
	    int p,v;
	    cin >> p >> v;
	    a.set(p-1,v);
	    cout << a.query() << endl;
	}
}