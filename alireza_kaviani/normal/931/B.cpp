#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl

int c(int a)
{
    return a/2+a%2;
}

int solve(int a , int b)
{
    if(c(a)==c(b))
    {
        return 1;
    }
    return 1+solve(c(a),c(b));
}

int main()
{
    int n,a , b;
    cin >> n >> a >> b;
    int t = solve(a,b);
    if(t==log2(n))
    {
        cout << "Final!" << endl;
        return 0;
    }
    cout << t << endl;
    return 0;
}