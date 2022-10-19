 //Arayi
#include <bits/stdc++.h>
#define fr first
#define sc second
#define MP make_pair
#define ad push_back
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jigglypuff
#define ld long double
#define itn int
#define pir pair<int, int>
#define all(x) (x).begin(), (x).end()
#define str string
#define enl endl
#define en endl
#define cd complex<long double>
#define vcd vector<cd>
#define vii vector<int>
#define vlli vector<lli>
using namespace std;
 
lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x, ld y1, ld x2, ld y2)
{
    return sqrt((x - x2) * (x - x2) + (y1 - y2) * (y1 - y2));
}
lli S(lli a)
{
    return (a * (a + 1LL)) / 2;
}
mt19937 rnd(363542);
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 0, -1, 1, -1, 1, 0 };
 
 
const int N = 1e6 + 20; 
const lli mod = 1e9+7;
const ld pi = acos(-1);
const int T = 200;
 
lli bp(lli a, lli b = mod - 2LL)
{
    lli ret = 1;
    while (b)
    {
        if (b & 1) ret *= a, ret %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ret;
}
ostream& operator<<(ostream& c, pir a)
{
    c << a.fr << " " << a.sc;
    return c;
}
template<class T>
void maxi(T& a, T b)
{
    a = max(a, b);
}
template <class T>
void mini(T& a, T b)
{
    a = min(a, b);
}


int t, n;
str s[N];
bool col[N], cl1[N], cl[N];
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        bool bl = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            if(s[i].size()==1) bl=1;
            else if(s[i].size() == 2)
            {
                if(s[i][0]==s[i][1]) bl=1;
                if(col[(s[i][1]-'a')+31*(s[i][0]-'a')]) bl=1;
                if(cl[(s[i][1]-'a')+31*(s[i][0]-'a')]) bl=1;
                col[(s[i][0]-'a')+31*(s[i][1]-'a')]=1;
            }
            else
            {
                if(s[i][0]==s[i][2]) bl=1;
                if(cl1[(s[i][2]-'a')+31*(s[i][1]-'a')+31*31*(s[i][0]-'a')]) bl=1;
                if(col[(s[i][2]-'a')+31*(s[i][1]-'a')]) bl=1;
                cl[(s[i][0]-'a')+31*(s[i][1]-'a')]=1;
                cl1[(s[i][0]-'a')+31*(s[i][1]-'a')+31*31*(s[i][2]-'a')]=1;
            }
        }
        if(bl) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        for (int i = 0; i < n; i++)
        {
            if(s[i].size() == 2)
                col[(s[i][0]-'a')+31*(s[i][1]-'a')]=0;
            else if(s[i].size() == 3)
            {
                cl[(s[i][0]-'a')+31*(s[i][1]-'a')]=0;
                cl1[(s[i][0]-'a')+31*(s[i][1]-'a')+31*31*(s[i][2]-'a')]=0;
            }
        }
        
    }
    
    return 0;
}

/*
    __
  *(><)*
    \/ /
    ||/
  --||
    ||
    /\
   /  \
  /    \
 
*/