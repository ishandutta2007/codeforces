#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    set<int> x;
    multiset<int> r;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        x.insert(a);
    }
    for(auto it = x.begin(); it != x.end(); ++it){
        auto it2 = it;
        it2++;
        if(it2 == x.end())
            continue;
        r.insert(*it2-*it);
    }
    if(n == 1)
        cout << 0 << '\n';
    else
        cout << *x.rbegin()-*x.begin()-*r.rbegin() << '\n';
    while(q--){
        int t, p;
        cin >> t >> p;
        if(t == 0){
            x.erase(p);
            if(x.size() <= 1)
                r.clear();
            else{
                if(p < *x.begin())
                    r.erase(r.find(*x.begin()-p));
                else if(p > *x.rbegin())
                    r.erase(r.find(p-*x.rbegin()));
                else{
                    auto it = x.lower_bound(p);
                    auto it2 = it;
                    it2--;
                    r.erase(r.find(*it-p));
                    r.erase(r.find(p-*it2));
                    r.insert(*it-*it2);
                }
            }
        }else{
            if(x.size() == 0){
                x.insert(p);
            }else{
                if(p < *x.begin())
                    r.insert(*x.begin()-p);
                else if(p > *x.rbegin())
                    r.insert(p-*x.rbegin());
                else{
                    auto it = x.lower_bound(p);
                    auto it2 = it;
                    it2--;
                    r.insert(*it-p);
                    r.insert(p-*it2);
                    r.erase(r.find(*it-*it2));
                }
                x.insert(p);
            }
        }
        if(x.size() <= 1)
            cout << 0 << '\n';
        else
            cout << *x.rbegin()-*x.begin()-*r.rbegin() << '\n';
    }
    return 0;
}