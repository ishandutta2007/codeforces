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




const int N = 1e6 + 30;



int n, t;
pir a[N];
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
                cin >> a[i].fr >> a[i].sc;
        }
        sort(a, a + n);
        priority_queue<int> q;
        int sm = 0;
        int pat = n;
        for (int i = 0; i < n; i++)
        {
            int i1 = lower_bound(a, a + n, MP(a[i].sc + 1, 0)) - a - i;
            i1 = n - i - i1;
            while (!q.empty() && -q.top() < a[i].fr) q.pop(), sm++;
            q.push(-a[i].sc);
            pat = min(pat, i1 + sm);
        }
        cout << pat << endl;
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