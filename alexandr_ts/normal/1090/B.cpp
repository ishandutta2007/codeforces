#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 1e6 + 10;
map<string, string> tl;
vector<string> a;
int main() {
    //freopen("a.in", "r", stdin);
    string s = "";
    while(true)
    {
        if (s[0] == '\\' && s[1] == 'b' && s[2] == 'e' && s[3] == 'g' && s[4] == 'i' && s[5] == 'n')
            break;
        cin >> s;
        //cout << s;
        if(s[0] == '\\' && s[1] == 'c' && s[2] == 'i' && s[3] == 't' && s[4] == 'e')
        {
            string k = "";
            for(int i = 6; i < s.size(); i++)
            {
                if(s[i] == '}')
                    break;
                k += s[i];
            }
            a.pb(k);
            //cout << k << endl;
        }
    }
    getline(cin, s);
    bool f = true;
    int r = 0;
    while(true)
    {
        string t = "";
        getline(cin, s);
        if (s[0] == '\\' && s[1] == 'e' && s[2] == 'n' && s[3] == 'd')
            break;
        int i = 0;
        while(s[i] != '{')
            i++;
        i++;
        while(s[i] != '}') {
            t += s[i];
            i++;
        }
        string k = "";
        i++;
        for(;i < s.size(); i++)
            k += s[i];
        tl[t] = k;
        //cout << t << " " << a[r] << endl;
        f = f && (a[r] == t);
        r++;
    }
    if (f)
    {
        cout << "Correct" << endl;
        return 0;
    }
    cout << "Incorrect\n";
    cout << "\\begin{thebibliography}{99}\n";
//    for(auto& it: tl)
//    {
//        cout << it.first << "." << it.second << endl;
//    }
    for(auto& it: a)
    {
        cout << "\\bibitem{" << it << "}" << tl[it] << endl;
    }
    cout << "\\end{thebibliography}\n";
}