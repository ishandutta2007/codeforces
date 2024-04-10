#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <list>
#include <cassert>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

struct GModInt {
    static int Mod;
    int x;
    GModInt(): x(0) { }
    GModInt(signed sig) { if((x = sig % Mod + Mod) >= Mod) x -= Mod; }
    GModInt(signed long long sig) { if((x = sig % Mod + Mod) >= Mod) x -= Mod; }
    int get() const { return x; }
    
    GModInt &operator+=(GModInt that) { if((x += that.x) >= Mod) x -= Mod; return *this; }
    GModInt &operator-=(GModInt that) { if((x += Mod - that.x) >= Mod) x -= Mod; return *this; }
    GModInt &operator*=(GModInt that) { x = (unsigned long long)x * that.x % Mod; return *this; }
    
    GModInt operator+(GModInt that) const { return GModInt(*this) += that; }
    GModInt operator-(GModInt that) const { return GModInt(*this) -= that; }
    GModInt operator*(GModInt that) const { return GModInt(*this) *= that; }
};
int GModInt::Mod = 0;

struct Matrix {
    typedef GModInt Num;
    vector<vector<Num> > v, w;
    Matrix() {}
    Matrix(int n, int m): v(n, vector<Num>(m)) { }
    inline int height() const { return (int)v.size(); }
    inline int width() const { return (int)v[0].size(); }
    inline Num& at(int i, int j) { return v[i][j]; }
    inline const Num& at(int i, int j) const { return v[i][j]; }
    static Matrix identity(int n) {
        Matrix A(n, n);
        rep(i, n) A.at(i, i) = 1;
        return A;
    }
    inline static Matrix identity(const Matrix& A) { return identity(A.height()); }
    Matrix& operator*=(const Matrix& B) {
        int n = height(), m = B.width(), p = B.height();
        assert(p == width());
        w.assign(n, vector<Num>(m, 0));
        rep(i, n) rep(j, m) {
            Num x = 0;
            rep(k, p) x += at(i, k) * B.at(k, j);
            w[i][j] = x;
        }
        v.swap(w);
        return *this;
    }
};
Matrix operator^(const Matrix& t, ll k) {
    Matrix A = t, B = Matrix::identity(t);
    while(k) {
        if(k & 1) B *= A;
        A *= A;
        k >>= 1;
    }
    return B;
}
ostream& operator<<(ostream& o, const Matrix& A) {
    int n = A.height(), m = A.width();
    rep(i, n) {
        o << "["; rep(j, m) o << A.at(i, j).get() << (j+1 == m ? "]\n" : ",");
    }
    return o;
}

int main() {
    int n; ll sx, sy, dx, dy, t;
    cin >> n >> sx >> sy >> dx >> dy >> t;
    sx --, sy --;
    GModInt::Mod = n;
    //(dx,dy,x,y,t) -> (2*dx+dy+x+y+t+3,2*dy+dx+x+y+t+3,x+dx,y+dy,t+1)
    Matrix A(6, 6);
    //save
    rer(i, 2, 5) A.at(i, i) = 1;
    rer(dxdy, 0, 1) A.at(dxdy, dxdy) = 2;
    A.at(0, 1) = A.at(1, 0) = 1;
    //x,y -> dx,dy
    rer(xy, 2, 3) rer(dxdy, 0, 1) A.at(xy, dxdy) = 1;
    //const -> dx,dy
    rer(dxdy, 0, 1) A.at(5, dxdy) = 3;
    //dx,dy -> x,y
    rer(dxdy, 0, 1) A.at(dxdy, 2+dxdy) = 1;
    //t -> dx, dy
    rer(dxdy, 0, 1) A.at(4, dxdy) = 1;
    //const -> t
    A.at(5, 4) = 1;
    Matrix b(1, 6);
    b.at(0, 0) = GModInt(dx + (sx+1) + (sy+1));
    b.at(0, 1) = GModInt(dy + (sx+1) + (sy+1));
    b.at(0, 2) = GModInt(sx);
    b.at(0, 3) = GModInt(sy);
    b.at(0, 4) = 0;
    b.at(0, 5) = 1; //constant
//  cerr << A<< endl;
//  cerr << b << endl;
    A = A ^ t;
//  cerr << A << endl;
    b *= A;
//  cerr << b << endl;
    cout << b.at(0, 2).get() + 1 << " " << b.at(0, 3).get() + 1 << endl;
    return 0;
}