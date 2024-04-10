#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}


int n, m;

bool valid(int x, int y)
{
    return 0 <= x && x <= n && 0 <= y && y <= m;
}

int main(int argc, char *argv[])
{
    //freopen("a.in", "r", stdin);
    
    
    cin >> n >> m;
    
    
    vector < pair < int, int > > a;
    
    if (valid(n, m))
        a.pb(mp(n, m));
    if (valid(n - 1, m))
        a.pb(mp(n - 1, m));
    if (valid(n - 2, m))
        a.pb(mp(n - 2, m));
    if (valid(n - 3, m))
        a.pb(mp(n - 3, m));
    if (valid(n, m - 1))
        a.pb(mp(n, m - 1));
    if (valid(n, m - 2))
        a.pb(mp(n, m - 2));
    if (valid(n, m - 3))
        a.pb(mp(n, m - 3));
    if (valid(0, 0))
        a.pb(mp(0, 0));
    if (valid(1, 0))
        a.pb(mp(1, 0));
    if (valid(2, 0))
        a.pb(mp(2, 0));
    if (valid(3, 0))
        a.pb(mp(3, 0));
    if (valid(0, 1))
        a.pb(mp(0, 1));
    if (valid(0, 2))
        a.pb(mp(0, 2));
    if (valid(0, 3))
        a.pb(mp(0, 3));
        
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
        
    ld ans = 0;
    vector < pair < int, int > > ansv;
    
    for (int i1 = 0; i1 < a.size(); i1++)
        for (int i2 = i1 + 1; i2 < a.size(); i2++)
            for (int i3 = i2 + 1; i3 < a.size(); i3++)
                for (int i4 = i3 + 1; i4 < a.size(); i4++)
                {
                    vector < pair < int, int > > b = vector < pair < int, int > > ({a[i1], a[i2], a[i3], a[i4]});
                    int p[] = {0, 1, 2, 3,};
        
                    do {
                        ld curr = 0;
                        for (int j = 0; j + 1 < 4; j++)
                        {
                            ld dx = b[p[j]].fst - b[p[(j + 1) % 4]].fst;
                            ld dy = b[p[j]].snd - b[p[(j + 1) % 4]].snd;
                            curr += sqrt(dx * dx + dy * dy);
                        }
                        if (curr >  ans)
                        {
                            ans = curr;
                            ansv.clear();
                            for (int j = 0; j < 4; j++)
                                ansv.pb(b[p[j]]);
                        }
                    } while (next_permutation(p, p + 4));
                }
    
    for (int i = 0; i < 4; i++)
        cout << ansv[i].fst << " " << ansv[i].snd << endl;
    
    
    return 0;
}