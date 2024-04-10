//Arayi
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>   
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <climits>
#include <cassert>
#include <chrono>
#include <random>
#include <complex>

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
const lli mod = 1e7 + 7;
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



int n, d;
int p[N], sz[N], col[N], sum;
set <pair<int, int> > st, sm;
int gp(int x)
{
    if(p[x]==x) return x;
    return p[x]=gp(p[x]);
}
int main()
{
    fastio;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) p[i]=i, sz[i]=1, sm.insert(MP(1,i));
    sm.erase(MP(1,1));
    st.insert(MP(1,1));
    int qn = 1;
    for (int i = 0; i < d; i++)
    {
        int a, b;
        cin >> a >> b;
        a=gp(a), b=gp(b);
        if(a==b) 
        {
            qn++;
            if(sm.size())
            {
                auto i1 = --sm.end();
                sm.erase(i1);
                st.insert(*i1);
                sum+=(*i1).fr;
            }
        }
        else
        {
            //cout << a << " " << b << endl;
            //for(auto i1 = st.begin(); i1 != st.end(); ++i1) cout<<(*i1).fr<<" "<<(*i1).sc<<endl;
            sm.erase(MP(sz[a],a));
            sm.erase(MP(sz[b],b));
            if(st.erase(MP(sz[a],a))) sum-=sz[a];
            if(st.erase(MP(sz[b],b))) sum-=sz[b];
            p[a]=b;
            sz[b]+=sz[a];
            st.insert(MP(sz[b], b)), sum+=sz[b];
            //cout<<" "<<sz[b]<<endl;
            if(sm.size()) 
            {
                auto i1 = --sm.end();
                sm.erase(i1);
                st.insert(*i1);
                sum+=(*i1).fr;
            }
            while (st.size()>qn)
            {
                auto i1 = st.begin();
                st.erase(i1);
                sm.insert(*i1);
                sum-=(*i1).fr;
            }
            //for(auto i1 = st.begin(); i1 != st.end(); ++i1) cout<<(*i1).fr<<" "<<(*i1).sc<<endl;
        }
        cout<<sum<<"\n";
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