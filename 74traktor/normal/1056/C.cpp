#include <bits/stdc++.h>

using namespace std;

int use[4000];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[2 * n];
    map < int, int > cila;
    set < pair < int, int > > s;
    map < int, int > ss;
    for (int i = 0; i < 2 * n; ++i){
        int x;
        cin >> x;
        s.insert({x, i});
        cila[i] = x;
    }
    vector < pair < int, int > > matr;
    for (int i = 0; i < m; ++i){
        int r, t;
        cin >> r >> t;
        if (r != t)
        matr.push_back({r, t});
        ss[r] = t;
        ss[t] = r;
    }
    int t;
    cin >> t;
    if (t == 1){
        for (auto key : matr){
            int q = cila[key.first - 1], w = cila[key.second - 1];
            if (q > w){
                cout << key.first << endl;
            }
            else{
                cout << key.second << endl;
            }
            s.erase({q, key.first - 1});
            s.erase({w, key.second - 1});
            cout.flush();
            int x;
            cin >> x;
        }
        while (s.size() > 0){
            auto p = (*s.rbegin());
            s.erase(p);
            cout << p.second + 1 << endl;
            cout.flush();
            int x;
            cin >> x;
            s.erase({cila[x - 1], x - 1});
        }
    }
    else{
        int x;
        cin >> x;
        while (s.size() > 0 && ss.find(x) != ss.end()){
            int prom = ss[x];
            cout << prom << endl;
            cout.flush();
            s.erase({cila[prom - 1], prom - 1});
            s.erase({cila[x - 1], x - 1});
            if (s.size() != 0)
                cin >> x;
        }
        s.erase({cila[x - 1], x - 1});

        for (auto key : matr){
            if (s.find({cila[key.first - 1], key.first - 1}) != s.end()){
                int q = cila[key.first - 1], w = cila[key.second - 1];
                if (q > w)
                    cout << key.first << endl;
                else
                    cout << key.second << endl;
                cout.flush();
                s.erase({cila[key.first - 1], key.first - 1});
                s.erase({cila[key.second - 1], key.second - 1});
                int x;
                cin >> x;
            }
        }

        while (s.size() > 1){
            auto p = (*s.rbegin());
            s.erase(p);
            cout << p.second + 1 << endl;
            cout.flush();
            int pty;
            cin >> pty;
            s.erase({cila[pty - 1], pty - 1});
        }
        if (s.size() > 0){
            cout << (*s.begin()).second +  1<< endl;
            cout.flush();
        }
    }
    return 0;
}