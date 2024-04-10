#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int w, h, n;
    cin >> w >> h >> n;
    multiset<int, greater<int>> W{w};
    multiset<int, greater<int>> H{h};
    set<int> ww{0, w};
    set<int> hh{0, h};
    while(n--)
    {
        char t;
        cin >> t;
        int x;
        cin >> x;
        if(t == 'V')
        {
            auto it = ww.upper_bound(x);
            auto t = it;
            t--;
            W.erase(W.lower_bound(*it - *t));
            W.insert(*it - x);
            W.insert(x - *t);
            ww.insert(x);
        }
        else
        {
            auto it = hh.upper_bound(x);
            auto t = it;
            t--;
            H.erase(H.lower_bound(*it - *t));
            H.insert(*it - x);
            H.insert(x - *t);
            hh.insert(x);
        }
        cout << 1LL * *W.begin() * *H.begin() << "\n";
    }
    return 0;
}