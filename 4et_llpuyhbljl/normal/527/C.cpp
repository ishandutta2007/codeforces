#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
using namespace std;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
inline int getint() {
    int val = 0;
    char c;
    while ((c = getchar()) && !(c >= '0' && c <= '9'));
    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));
    return val;
}
const long long INF = -1000;
const int Y = 100;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m, q;
    vector<long long>ans;
    cin >> n >> m >> q;
    multiset<long long>f, s;
    f.insert(n);
    s.insert(m);
    set<int>y1;
    set<int>y2;
    y1.insert(0);
    y1.insert(n);
    y2.insert(0);
    y2.insert(m);
    while (q--) {
        char tp; int vl;
        cin >> tp >> vl;
        if (tp == 'V') {
            auto it1 = y1.lower_bound(vl);
            int bo = *it1;
            int me = *--it1;
            int l1 = vl - me;
            int l2 = bo - vl;
            f.erase(f.find(l1 + l2));
            f.insert(l1);
            f.insert(l2);
            y1.insert(vl);
        }
        else {
            auto it1 = y2.lower_bound(vl);
            int bo = *it1;
            int me = *--it1;
            int l1 = vl - me;
            int l2 = bo - vl;
            s.erase(s.find(l1 + l2));
            s.insert(l1);
            s.insert(l2);
            y2.insert(vl);
        }
        auto it1 = f.end(), it2 = s.end();
        --it1;
        --it2;
        ans.push_back((*it1) * (*it2));
    }



    for (auto x : ans)cout << x << "\n";
    return 0;
}