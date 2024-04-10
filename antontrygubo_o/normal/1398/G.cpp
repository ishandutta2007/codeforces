#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;


const int p = 1000000007;


int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=p) s-=p;
    return s;
}

int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}


mt19937 rnd(time(0));

/*
const int N = 1200000;

vector<int> facs(N), invfacs(N);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<N; i++) facs[i] = mul(facs[i-1], i);
    invfacs[N-1] = inv(facs[N-1]);
    for (int i = N-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    if (n<k) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}
*/


template <typename T>
struct Complex {
    T real, imag;
    Complex(T x=(T)0, T y=(T)0) : real(x), imag(y) {}
    Complex conj() { return Complex(real, -imag); }
    Complex operator+(const Complex& c) { return Complex(real + c.real, imag + c.imag); }
    Complex operator-(const Complex& c) { return Complex(real - c.real, imag - c.imag); }
    Complex operator*(const T& num) { return Complex(real * num, imag * num); }
    Complex operator/(const T& num) { return Complex(real / num, imag / num); }
    Complex operator*(const Complex& c) {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }
    Complex operator/(const Complex& c) {
        return *this * c.conj() / (c.x * c.x + c.y * c.y);
    }
};

typedef long long itype;
typedef long double dtype;

typedef Complex<dtype> ftype;
typedef vector<itype> poly;
const dtype PI = 4 * atan((dtype) 1);

void fft(ftype* A, int n, bool inv=false) {
    for (int i = 1, j = n / 2; i + 1 < n; i++) {
        if (i < j) swap(A[i], A[j]);
        int t = n / 2;
        while (j >= t) j -= t, t >>= 1;
        j += t;
    }
    for (int h = 2; h <= n; h <<= 1) {
        ftype wm(cos(2 * PI / h), sin(2 * PI / h));
        for (int i = 0; i < n; i += h) {
            ftype w(1);
            for (int j = i; j < i + h / 2; j++) {
                ftype x = A[j], y = w * A[j + h / 2];
                A[j + h / 2] = x - y;
                A[j] = x + y;
                w = w * wm;
            }
        }
    }
    if (inv) {
        reverse(A + 1, A + n);
        for (int i = 0; i < n; i++) {
            A[i] = A[i] / n;
        }
    }
}

poly pmul(poly p, poly q) {
    int dim = p.size() + q.size() - 1;
    while (__builtin_popcount(dim) != 1) ++dim;
    ftype* a = new ftype[dim];
    ftype* b = new ftype[dim];
    for (int i = 0; i < p.size(); i++)
        a[i] = p[i];
    for (int i = 0; i < q.size(); i++)
        b[i] = q[i];
    fft(a, dim);
    fft(b, dim);
    for (int i = 0; i < dim; i++)
        a[i] = a[i] * b[i];
    fft(a, dim, true);
    poly res(dim);
    for (int i = 0; i < dim; i++)
        res[i] = round(a[i].real);
    while (res.size() && !res.back())
        res.pop_back();
    delete[] a;
    delete[] b;
    return res;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, x, y;
    cin>>n>>x>>y;

    vector<int> a(n+1);
    for (int i = 0; i<=n; i++) cin>>a[i];

    poly A(x+1);
    for (auto it: a) A[it] = 1;
    poly B(x+1);
    for (auto it: a) B[x-it] = 1;

    poly res = pmul(A, B);

    /*for (auto it: A) cout<<it<<' ';
    cout<<endl;
    for (auto it: B) cout<<it<<' ';
    cout<<endl;

    cout<<res.size()<<endl;

    for (auto it: res) cout<<it<<' ';
    cout<<endl;*/

    vector<bool> good(1e6+1);
    for (int i = x+1; i<res.size(); i++) if (res[i]>0) good[2*(i-x) + 2*y] = 1;

    //cout<<"good"<<endl;

    vector<int> answer(1e6+1, -1);
    for (int i = 1; i<=1e6; i++) if (good[i])
    {
        //cout<<i<<' ';
        for (int j = i; j<=1e6; j+=i) answer[j] = i;
    }
    //cout<<endl;

    int q; cin>>q;
    for (int i = 0; i<q; i++)
    {
        int tmp; cin>>tmp; cout<<answer[tmp]<<' ';
    }

}