///Lol kek cheburek///
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< pii > vii;
typedef double ld;

#define pb push_back
#define mp make_pair
#define ins insert
#define ers erase

#define elif else if
#define all(v) (v).begin(),(v).end()
#define len(s) int((s).size())

#define fi first
#define se second
#define x first
#define y second

#define fpos krevedka
#define left Levo
#define right ishtenem
#define next nastupniy
#define prev poperedniy
#define div dilyty_sukotay

#define I64 "%lld"

#define I "%d"
#define II I I
#define III II I
#define IIII II II
#define IIIII III II
#define IIIIII III III
#define IIIIIII IIII III
#define IIIIIIII IIII IIII

#define dbg cout << "dbg\n"
#define files(name) freopen(name".in", "r", stdin);freopen(name".out","w", stdout);
#define UOIfiles(name) freopen(name".dat", "r", stdin);freopen(name".sol","w", stdout);


ld sqr(ld x) {return x * x;}

const ll md = 1e9 + 7;
const ll md2 = 2e9 + 7;
const ld PI = acos(-1);
const int MAXN = 2e6 + 1;
const int INF = 1e9 + 1;
const int RNG = 1e8 + 10;
const pii turns[4] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
const char signs[4] = {'D', 'L', 'R', 'U'};

///end template ///

string s;
char a[2000][2000];

int main()
{
    //UOIfiles("split");
    ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    cin >> s >> s;
    int maxDepth = 0, depth = 0;
    for(auto c : s) {
        if(c == '[') depth++;
        else depth--;
        maxDepth = max(maxDepth, depth);
    }
    int n = len(s), m = 2 * maxDepth + 1;
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            a[i][j] = ' ';
        }
    }

    int x = 0, y = maxDepth;
    for(int j = 0; j < len(s); j++) {
        char c = s[j];

        for(int i = 0; i < maxDepth; i++) {
            a[x][y + i] = a[x][y - i] = '|';
        }
        a[x][y - maxDepth] = a[x][y + maxDepth] = '+';
        if(c == '[') {
            a[x + 1][y - maxDepth] =
                a[x + 1][y + maxDepth] = '-';
        }
        else {
            a[x - 1][y - maxDepth] =
                a[x - 1][y + maxDepth] = '-';
        }

        if(j + 1 != len(s)) {
            x++;
            if(s[j] == '[' && s[j + 1] == '[') {
                maxDepth--;
            }
            else if(s[j] == ']' && s[j + 1] == ']') {
                maxDepth++;
            }
            else if(s[j] == '[' && s[j + 1] == ']') {
                x += 3;

            }
        }
    }
    for(int j = 0; j < m; j++) {
        vector<char> v;
        for(int i = 0; i <= x; i++) {
            v.pb(a[i][j]);
        }
        while(v.back() == ' ') v.pop_back();
        for(auto c : v)
            cout << c;
        cout << "\n";
    }
}