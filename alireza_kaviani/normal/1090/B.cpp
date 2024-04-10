#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pld;
typedef pair<string, string> pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll input() {
    ll n;
    cin >> n;
    return n;
}

ll pw(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % md, b / 2, md) % md : pw(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

vector<string> names , answers;
string s , mode = "1" , name , t;
map<string , string> mp;

string getName(string s)
{
    ll l , r;
    for(ll i = 0 ; i < s.size() ; i++)
    {
        if(s[i] == '{') l = i;
        if(s[i] == '}')
        {
            r = i;
            break;
        }
    }
    return s.substr(l + 1 , r - l - 1);
}

int main() {
    fast_io;
    set_random;

    while(1)
    {
        cin >> s;
        if(s == "\\begin{thebibliography}{99}") mode = "2";
        if(s == "\\end{thebibliography}")
        {
            if(t != "")
            {
                mp[name] = t;
            }
            break;
        }

        if(mode == "1" && s.substr(0 , 5) == "\\cite")
        {
            names.push_back(getName(s));
        }
        if(mode == "2" && s.substr(0 , 8) == "\\bibitem")
        {
            if(t != "")
            {
                mp[name] = t;
            }
            name = getName(s);
            answers.push_back(name);
            t = "";
        }
        if(mode == "2")
        {
            t += s + " ";
        }
    }

    if(answers == names)    return cout << "Correct" << endl , 0;
    cout << "Incorrect" << endl;
    cout << "\\begin{thebibliography}{99}" << endl;
    for(string i : names) cout << mp[i].substr(0 , mp[i].size() - 1) << endl;
    cout << "\\end{thebibliography}" << endl;

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea(use for loop for floats)
    5- don't forget printf and scanf can help you in your code speed
*/