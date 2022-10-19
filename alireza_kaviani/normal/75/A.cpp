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
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<int> vect(ll n)
{
    vector<int> ans;
    while(n != 0)
    {
        ans.push_back(n % 10);
        n /= 10;
    }
    return ans;
}

vector<int> rz(vector<int> vec)
{
    vector<int> ans;
    for(int i : vec)
    {
        if(i != 0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

vector<int> sum(vector<int> a , vector<int> b)
{
    vector<int> ans;
    int add = 0;
    for(int i = 0 ;i < max(a.size() , b.size()) ; i++)
    {
        int t = 0;
        if(i >= b.size())
        {
            t = add + a[i];
        }
        else if(i >= a.size())
        {
            t = add + b[i];
        }
        else
        {
            t = add + a[i] + b[i];
        }

        add = t / 10;
        ans.push_back(t % 10);
    }
    if(add != 0)
    {
        ans.push_back(add);
    }

    return ans;
}

void PrintVec(vector<int> vec)
{
    for(int i : vec)
    {
        cout << i;
    }
    cout << endl;
}

int main()
{
    fast_io;

    ll n , m;
    cin >> n >> m;

    vector<int> a , b , s , s2;
    a = rz(vect(n));
    b = rz(vect(m));
    s = rz(vect(n + m));
    s2 = sum(a , b);

    //PrintVec(a);
    //PrintVec(b);
    //PrintVec(s);
    //PrintVec(s2);

    if(s2 == s)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}