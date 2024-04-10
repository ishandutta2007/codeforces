#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

#define all(x) x.begin(), x.end()
#define f(i,a,b) for(int i = (a); i <= (b); i++)
#define fd(i,a,b) for(int i = (a); i >= (b); i--)
#define mp make_pair
#define faster_io() ios_base::sync_with_stdio(false)
#define pb push_back
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define vii vector<pair<int,int>>

const int INF = 1000000002;
const ll INFLL = 100000000000000000ll;
const ll MOD = 1000000007;

// ----------------------------------------------------------------------------------------------------------

int K;
vector<string> v = {"++**","+*+*","++++","+**+"};

string rev(string s)
{
    string ret = "";
    f(i,0,SZ(s)-1)
    {
        if(i%2)
        {
            if(s[i] == '*') ret += '+';
            else ret += '*';
        }
        else ret += s[i];
    }

    return ret;
}

int main()
{
    cin >> K;
    if(K == 0)
    {
        cout << "*";
        return 0;
    }
    if(K == 1)
    {
        cout << "++\n+*";
        return 0;
    }

    f(i,3,K)
    {
        vector<string> temp;

        f(i,0,SZ(v)-1)
        {
            string s = v[i];
            string t = "";
            f(p,0,SZ(s)-1) f(times,0,1) t += s[p];
            temp.pb(t);
        }

        int n = SZ(temp);
        f(i,0,n-1) temp.pb(rev(temp[i]));
        v = temp;
    }

    for(string s : v) cout << s << "\n";
}