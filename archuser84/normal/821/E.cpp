#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

const int mod = 1e9 + 7;

template<class T>
class MyMat
{
private:
    int h, w;
    T** mat = 0;
public:
    void clear() {
        if(mat) {
            for(int i = 0; i < h; ++i)
                delete[](mat[i]);
            delete[](mat); mat = 0;
        }
        h = 0; w = 0;
    }
    MyMat() : h(0), w(0) {}
    MyMat(int n, int m) {
        h = n; w = m;
        mat = new T*[h];
        for(int i = 0; i < h; ++i)
            mat[i] = new T[w]{};
    }
    MyMat(int n, int m, initializer_list<T> il) {
        h = n; w = m;
        mat = new T*[h];
        for(int i = 0; i < h; ++i) {
            mat[i] = new T[w];
            for(int j = 0; j < w; ++j)
                mat[i][j] = il.begin()[i*w + j];
        }
    }
    MyMat(const MyMat & x){
        h = x.h; w = x.w;
        mat = new T*[h];
        for(int i = 0; i < h; ++i) {
            mat[i] = new T[w];
            for(int j = 0; j < w; ++j)
                mat[i][j] = x.mat[i][j];
        }
    }
    ~MyMat(){clear();}
    inline int height() { return h; }
    inline int width() { return w; }
    T* operator[](int i){return mat[i];}
    MyMat& operator=(const MyMat & x) {
        if(this == &x) return *this;
        clear();
        h = x.h; w = x.w;
        mat = new T*[h];
        for(int i = 0; i < h; ++i) {
            mat[i] = new T[w];
            for(int j = 0; j < w; ++j)
                mat[i][j] = x.mat[i][j];
        }
        return *this;
    }
};

template<class T>
ostream& operator<<(ostream& str, MyMat<T> A)
{
    str << char(218) << ' ';
    for(int j = 0; j < A.width()-1; ++j)
        str << A[0][j] << ", ";
    str << A[0][A.width()-1] << '\n';

    for(int i = 1; i < A.height()-1; ++i) {
        str << char(179) << ' ';
        for(int j = 0; j < A.width()-1; ++j)
            str << A[i][j] << ", ";
        str << A[i][A.width()-1] << '\n';
    }

    str << char(192) << ' ';
    for(int j = 0; j < A.width()-1; ++j)
        str << A[A.height()-1][j] << ", ";
    str << A[A.height()-1][A.width()-1] << '\n';

    return str;
}

template<class T>
MyMat<T> operator*(MyMat<T> A, MyMat<T> B)
{
    if(A.width() != B.height()) throw("Wrong dimensions!");
    MyMat<T> ans(A.height(), B.width());
    for(int i = 0; i < A.height(); ++ i)
        for(int j = 0; j < B.width(); ++j)
            for(int k = 0; k < A.width(); ++k)
                ans[i][j] = (ans[i][j] + A[i][k] * B[k][j]) % mod;
    return ans;
}

template<class T>
MyMat<T> Id(int n) {
    MyMat<T> ans(n, n);
    for(int i = 0; i < n; ++i)
        ans[i][i] = 1;
    return ans;
}

template<class T>
MyMat<T> matPow(MyMat<T> A, ll e, int mod = ::mod)
{
    if(A.width() != A.height()) throw("Wrong dimensions!");
    MyMat<T> ans = Id<T>(A.width());
    for(; e; e >>= 1)
    {
        if(e&1) ans = ans*A;
        A = A*A;
    }
    return ans;
}


const int N = 110;
ll a[N], b[N];
int c[N];
int n;
ll k;
MyMat<ll> ans(16, 1);
MyMat<ll> x(16, 16);

int main()
{
    FAST;
    cin >> n >> k;
    ans[0][0] = 1;
    Loop(i,0,n)
        cin >> a[i] >> b[i] >> c[i];
    b[n-1] = k;
    Loop(i,1,n)
        if(c[i] < c[i-1]) b[i-1]--;
        else              a[i]++;
    ans[0][0] = 1;
    Loop(k,0,n)
    {
        Loop(i,0,16)
            Loop(j,0,16)
                x[i][j] = (abs(i-j) <= 1 && i <= c[k]);
        //cerr << x;
        ans = matPow(x, k? b[k] - b[k-1]: b[k])*ans;
        //cerr << ans;
    }
    //cerr << ans;
    cout << ans[0][0] << '\n';
}