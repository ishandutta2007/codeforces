#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;

multiset <int> atk;
vector <int> v_atk;
multiset <int> def;
multiset <int> mine;
vector <int> v_mine;

int do_damage(multiset <int> from, multiset <int> to) {
    int damage = 0;

    bool missed = false;
    for (multiset <int> :: reverse_iterator it = from.rbegin(), it2 = to.rbegin(); it != from.rend(); ++ it) {
        while (it2 != to.rend() && *it < *it2) {
            ++ it2;
            missed = true;
        }
        if (it2 == to.rend())
            missed = true;
        else {
            damage += (*it - *it2);
            ++ it2;
        }
    }

    if (missed)
        return 0;
    else
        return damage;
}

int main()
{
    int n, m;
    cin >> n >> m;

    string str;
    int val;
    for (int i = 1; i <= n; ++ i) {
        cin >> str >> val;
        if (str == "ATK") {
            atk.insert(val);
            v_atk.push_back(val);
        }
        else
            def.insert(val);
    }

    for (int i = 1; i <= m; ++ i) {
        cin >> val;
        mine.insert(val);
        v_mine.push_back(val);
    }

    sort(v_atk.begin(), v_atk.end());
    sort(v_mine.begin(), v_mine.end());

    //Try without breaking armor
    int ans = 0;
    for (int cnt = 0; cnt < atk.size() && cnt < mine.size(); ++ cnt) {
        if (v_mine[v_mine.size() - cnt - 1] - v_atk[cnt] < 0)
            break;
        ans += v_mine[v_mine.size() - cnt - 1] - v_atk[cnt];
    }

    //Remove armor
    for (auto it: def) {
        multiset <int> :: iterator it2 = mine.upper_bound(it);
        if (it2 == mine.end()) {
            cout << ans << '\n';
            return 0;
        }

        mine.erase(it2);
    }

    //Add additional 0
    if (atk.size() > mine.size()) {
        cout << ans << '\n';
        return 0;
    }
    while (atk.size() < mine.size())
        atk.insert(0);

    //Do the rest of the damage
    ans = max(ans, do_damage(mine, atk));

    cout << ans << '\n';
    return 0;
}