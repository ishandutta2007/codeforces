#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        vector<multiset<int>> a(2);
        for(int i = 0; i < n0; ++i){
            a[0].insert(0);
            a[0].insert(0);
        }
        for(int i = 0; i < n1; ++i){
            a[1].insert(0);
            a[0].insert(1);
        }
        for(int i = 0; i < n2; ++i){
            a[1].insert(1);
            a[1].insert(1);
        }
        stack<int> b;
        vector<int> p;
        int v = 0;
        if(a[0].size() == 0)
            v = 1;
        b.push(v);
        while (!b.empty()) {
            int v = b.top();
            if (a[v].size() == 0) {
                p.push_back(v);
                b.pop();
            }
            else {
                auto it = a[v].begin();
                int x = *it;
                b.push(x);
                a[v].erase(it);
                it = a[x].find(v);
                a[x].erase(it);
            }
        }
        for(int i = 0; i < p.size(); ++i)
            cout << p[i];
        cout << '\n';
	}
	return 0;
}