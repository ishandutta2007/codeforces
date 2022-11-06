#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define mod 1000000007
#define maxN 1000011

struct palindromic_tree {
    int n, act;
    vector< map<char, int> > list;
    vector<int> link, slink, diff, len;
    string s;

    void add_node() {
        n++;
        list.emplace_back();
        link.emplace_back();
        slink.emplace_back();
        diff.emplace_back();
        len.emplace_back();
    }

    palindromic_tree() {}

    palindromic_tree(string _s) {
        n = -1; act = 0;
        list.clear();
        link = slink = diff = len = {};
        s = _s;

        add_node();
        len[0] = -1;
        add_node();
        link[1] = 0;

        act = 1;
    }

    void add_letter(int id) {
        while (act != 0 && s[id] != s[id - len[act] - 1])
            act = link[act];

        if (s[id] == s[id - len[act] - 1]) {
            if (list[act][s[id]] == 0) {
                add_node();
                list[act][s[id]] = n;
                len[n] = len[act] + 2;

                if (act != 0) {
                    link[n] = link[act];
                    while (link[n] != 0 && s[id] != s[id - len[link[n]] - 1])
                        link[n] = link[link[n]];

                    if (s[id] == s[id - len[link[n]] - 1])
                        link[n] = list[link[n]][s[id]];
                } else {
                    link[n] = 1;
                }

                diff[n] = len[n] - len[link[n]];
                if (diff[n] == diff[link[n]])
                    slink[n] = slink[link[n]];
                else
                    slink[n] = link[n];
            }


            act = list[act][s[id]];
        }
    }

};

string s, aux;
int n, i, j;

ll dp[maxN], serie[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    cin >> s;
    n = s.size();

    aux = "@";
    i = 0; j = n - 1;
    while (i < j) {
        aux.pb(s[i++]);
        aux.pb(s[j--]);
    }

    palindromic_tree PT(aux);
    dp[0] = 1;
    for (i = 1; i <= n; i++) {
        PT.add_letter(i);

        for (int act = PT.act; act != 0; act = PT.slink[act]) {
            serie[act] = dp[i - (PT.len[PT.slink[act]] + PT.diff[act] )]; //! adauga bucata cea mai mica din serie
            if (PT.diff[act] == PT.diff[PT.link[act]]) {
                serie[act] += serie[PT.link[act]];
                serie[act] %= mod;
            }
            dp[i] += serie[act];
            dp[i] %= mod;
        }

        if (i & 1) dp[i] = 0;
    }

    cout << dp[n];


    return 0;
}