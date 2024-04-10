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
#include <cassert>
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
using namespace std;

lli gcd(lli a, lli b) { return (b == 0 ? a : gcd(b, a % b)); }

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };



const int N = 1e5;
const lli mod = 1e9 + 7;
int q, n, k;
string s;
int main()
{
    fastio;
    cin >> q;
    while(q--)
    {
        vector <pair<int, int> > pat;
        cin >> n >> k >> s;
        int i1 = 0;
        while(k > 1)
        {
            for (int i = i1; i < n - 1; i++)
            {
                if(s[i] == ')' && s[i + 1] == '(')
                {
                    pat.PB(MP(i1, i + 1));
                    reverse(s.begin() + i1, s.begin() + i + 2);
                    break;
                }
                else if(s[i] == '(' && s[i + 1] == ')')
                {

                    pat.PB(MP(i, i + 1));
                    reverse(s.begin() + i, s.begin() + i + 2);
                    pat.PB(MP(i1, i + 1));
                    reverse(s.begin() + i1, s.begin() + i + 2);
                    break;
                }
            }
            k--;
            i1+=2;
        }
        for (int i = i1; i < n; i++)
        {
            if(s[i] == '(')
            {
                pat.PB(MP(i1, i));
                reverse(s.begin() + i1, s.begin() + i + 1);
                i1++;
            }
        }
        cout << pat.size()<<"\n";
        for(auto p : pat)
        {
            cout << p.fr + 1 << " " << p.sc + 1 << "\n";
        }
        //cout << s << endl;
    }
    return 0;
}