#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

ll p = 1e9 + 7;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
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

mt19937 rnd(228);
ll n, m;

struct Matrix
{
    int size;
    vector<vector<int>> M;
    Matrix(int m)
    {
        size = m;
        M = vector<vector<int>> (m, vector<int>(m));
    }
};

Matrix prod(Matrix a, Matrix b)
{
    Matrix c(m);
    for (int i = 0; i<m; i++)
    for (int j = 0; j<m; j++)
    {
        for (int k = 0; k<m; k++) 
        c.M[i][j] = add(c.M[i][j], mul(a.M[i][k], b.M[k][j]));
    }
    return c;
}

vector<int> prod_vec(vector<int> a, Matrix b)
{
    vector<int> res(m);
    for (int i = 0; i<m; i++) 
    for (int j = 0; j<m; j++) res[i] = add(res[i], mul(a[j], b.M[j][i]));
    return res;
}

Matrix init()
{
    Matrix res(m);
    for (int i = 0; i<m-1; i++) res.M[i+1][i] = 1;
    res.M[0][m-1] = 1;
    res.M[m-1][m-1] = 1;
    return res;
}

Matrix identity()
{
    Matrix res(m);
    for (int i = 0; i<m; i++) res.M[i][i] = 1;
    return res;
}

Matrix poM(Matrix c, ll deg)
{
    if (deg==0) return identity();
    if (deg%2==1) return prod(poM(c, deg-1), c);
    Matrix t = poM(c, deg/2);
    return prod(t, t);
}

void write(Matrix a)
{
    for (int i = 0; i<n; i++) print(a.M[i]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n>>m;
    vector<int> a(m);
    for (int i = 0; i<m; i++) a[i] = 1;
    //print(a);
    Matrix temp = init();
    //write(temp);
    if (n<m) {cout<<a[n]; return 0;}
    Matrix res = poM(temp, n-m+1);
    //write(res);
    vector<int> ans = prod_vec(a, res);
    cout<<ans[m-1];

    
    
}