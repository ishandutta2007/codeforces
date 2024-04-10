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



const int N = 1e6 + 30;
const lli mod = 1e9 + 7;

int q;
string s;
 int main()
 {
     fastio;
    cin >> q;
    while(q--)
    {
        vector <int> pat;
        cin >> s;
        s+='#';
        for (int i = 0; i < s.length() - 2; i++)
        {
            if(s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o')
            {
                if(s[i + 3] != 'o') {pat.PB(i+2), i+=2;}
                else {pat.PB(i + 1), i++;}
            }
            else if(s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e')
            {
                pat.PB(i + 1), i++;
            }
        }
        cout<<pat.size()<<endl;
        for(auto p:pat) cout<<p+1<<" ";
        cout<<endl;
    }
     return 0;
 }