#include <bits/stdc++.h>
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e5;
const ll INF = 1e9;
const ld EPS = 1e-9;


int main() {
    //freopen("a.in", "r", stdin);
    int m, k;
    cin >> m >> k;
    int t1, t2;
    set <int> s;
    set <pair <int, int>  >st;
    for (int i = 0; i < m; i++)
    {
        cin >> t1 >> t2;
        s.insert(t1);
        s.insert(t2);
        st.insert(mp(min(t1, t2), max(t1, t2)));
    }
    vector <int> a[1000];
    int cur = -1;
    for (set <int> :: iterator it1 = s.begin(); it1 != s.end(); it1++) {
        cur++;
        for (set <int> :: iterator it2 = s.begin(); it2 != s.end(); it2++)
        {
            if (*it1 != *it2 && !st.count(mp(min(*it1, *it2), max(*it1, *it2))))
            {
                int qua = 0, quatot = 0;
                for (set <int> :: iterator it3 = s.begin(); it3 != s.end(); it3++) {
                    if (st.count(mp(min(*it1, *it3), max(*it1, *it3))) && st.count(mp(min(*it3, *it2), max(*it3, *it2))))
                    {
                        qua++;
                    }
                    if (st.count(mp(min(*it1, *it3), max(*it1, *it3))))
                        quatot++;
                }
                if (100 * qua >= k * quatot)
                    a[cur].push_back(*it2);//cout << *it2 << " ";
            }
        }
    }
    cur = -1;
    for (set <int> :: iterator it1 = s.begin(); it1 != s.end(); it1++) {
        cur++;
        cout << *it1 << ": ";
        cout << a[cur].size() << " ";
        for (int i = 0; i < a[cur].size(); i++)
            cout << a[cur][i] << " ";
        cout << endl;
    }
}