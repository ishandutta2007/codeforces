#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second
#define MAXN 300100
lli fib[MAXN], pre1[MAXN], pre2[MAXN], MOD = 1e9 + 9;
vector <lli> zero(4, 0), fibb[MAXN];

void Add(lli &A, lli B) {
    A += B;
    if (A > MOD) A -= MOD;
}

void mul1 (vector <lli> &A, vector <lli> &B) {
	vector <lli> ans(4, 0);
	fop (i,0,2) {
		fop (j,0,2) {
			fop (k,0,2) {
				Add(ans[i*2+j], A[i*2+k] * B[k*2+j] % MOD);
			}
		}
	}
	swap(A, ans);
}

void mul2 (vector <lli> &A, int n) {
    mul1(A, fibb[n]);
}

void add (vector <lli> &A, vector <lli> B) {
    fop (i,0,4) Add(A[i], B[i]);
}


struct Seg {
	int l,r,m;
	lli sum;
	vector <lli> addTag;
	Seg* ch[2];
	Seg (int l, int r, vector <lli> &A): l(l), r(r), m(l + r >> 1) {
		sum = 0;
		addTag.resize(4, 0);
		if (r - l != 1) {
			ch[0] = new Seg(l,m,A);
			ch[1] = new Seg(m,r,A);
			pull();
		} else {
			sum = A[l];
		}
	}
	int size() {return r - l;}
	void pull() {
	    sum = ch[0]->sum;
	    Add(sum, ch[1]->sum);
	}
	void addValue(vector <lli> &v) {
		Add(sum, v[0] * pre1[size()] % MOD);
		Add(sum, v[1] * pre2[size()] % MOD);
	}
	void push() {
		if (r - l != 1) {
			if (addTag[0] != 0 or addTag[1] != 0 or addTag[2] != 0 or addTag[3] != 0) {
				ch[0]->addValue(addTag);
				add(ch[0]->addTag, addTag);
				mul2(addTag, m - l);
				ch[1]->addValue(addTag);
				add(ch[1]->addTag, addTag);
			}
		}
		fop (i,0,4) addTag[i] = 0;
	}
	lli query(int a, int b) {
		if (a <= l and r <= b) return sum;
		push();
		lli ans = 0;
		if (a < m) Add(ans, ch[0]->query(a,b));
		if (m < b) Add(ans, ch[1]->query(a,b));
		return ans;
	}
	void addQuery(int a, int b) {
		if (a >= b) return;
		if (a <= l and r <= b) {
		    addValue(fibb[l - a]);
			add(addTag, fibb[l - a]);
		} else {
			push();
			if (a < m) ch[0]->addQuery(a,b);
			if (m < b) ch[1]->addQuery(a,b);
			pull();
		}
	}
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    fib[1] = fib[2] = 1;
    fop (i,3,MAXN) {
        fib[i] = fib[i-1];
        Add(fib[i], fib[i-2]);
    }
    pre1[1] = 1;
    pre2[1] = 1;
    fop (i,2,MAXN-1) {
        pre1[i] = pre1[i-1];
        Add(pre1[i], fib[i]);
        pre2[i] = pre2[i-1];
        Add(pre2[i], fib[i+1]);
    }
    zero[0] = zero[3] = 1;
    vector <lli> re(4, 1), fi(4, 1);
    re[0] = 0;
    fi[0] = 0;
    fibb[0] = zero;
    fibb[1] = re;
    fop (i,2,MAXN) {
        mul1(re, fi);
        fibb[i] = re;
    }
	
    int n,q;
    cin >> n >> q;
    vector <lli> input(n);
    fop (i,0,n) cin >> input[i];
    Seg tree(0, n, input);
    while (q--) {
        int a, l, r;
        cin >> a >> l >> r;
        l--;
        if (a == 1) {
            tree.addQuery(l, r);
        } else {
            cout << tree.query(l, r) << endl;
        }
        //fop (i,0,n) cout << tree.query(i,i+1) << " \n"[i == n - 1];
    }
}