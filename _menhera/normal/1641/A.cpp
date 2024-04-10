#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T; cin >> T; while(T--)
    {
        int n, x; cin >> n >> x;
        vector<int> a(n); for(int&v: a) cin >> v;
        multiset<long long> S;
        sort(a.begin(), a.end());
        for(long long y: a)
        {
            if(S.count(y)) S.erase(S.find(y));
            else S.insert(1LL*x*y);
        }
        cout << S.size() << endl;
    }
}