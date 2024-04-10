#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>
#define ll long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    // cout << s << endl;
    int n = s.size();
    vector<int> d;
    vector<int> a;
    char c = s[0];
    int now = 0;
    for (int i = 0; i < n; ++i){
        if (s[i] == c){
            now++;
            continue;
        }
        if (c == '_'){
            d.push_back(now);
            c = '#';
            now = 1;
            continue;
        }
        a.push_back(now);
        c = '_';
        now = 1;
        continue;
    }
    if (c == '_'){
        d.push_back(now);
    } else {
        a.push_back(now);
    }
    if (a.size() == 0){
        cout << "0\n";
        return 0;
    }
    if (d.size() == 0){
        cout << "1\n";
        cout << n << "\n";
        return 0;
    }

    int left = 0, right = 0;
    if (s[0] == '_')
        left = d[0];
    if (s[n - 1] == '_')
        right = d.back();

    int odd = 0, even = 0;
    set<int> as, ds;
    int A = 0, D = 0;
    for (auto elem : a){
        as.insert(elem);
        A += elem;
    }
    //cout << "here0" << endl;
    set<int> dbet;
    for (int i = 0; i < d.size(); ++i){
        auto elem = d[i];
        if (elem % 2 == 0)
            even += 1;
        else
            odd += 1;
        ds.insert(elem);
        if ((i != 0 || s[0] == '#') && (i + 1 != d.size() || s[n - 1] == '#'))
            dbet.insert(elem);
        D += elem;
    }
    if (s[0] == '_'){
        if (left % 2 == 0)
            even--;
        else
            odd--;
    }
    if (s[n - 1] == '_'){
        if (right % 2 == 0)
            even--;
        else
            odd--;
    }

    //cout << "here" << endl;

    bool flag0 = 1;
    for (int i = 0; i < n; ++i){
        if (i > 0 && s[i] == s[i - 1] && s[i] == '_'){
            flag0 = 0;
            break;
        }
        if (i < n - 1 && s[i] == s[i + 1] && s[i] == '_'){
            flag0 = 0;
            break;
        }
    }
    if (s[0] != '#' || s[n - 1] != '#'){
        flag0 = 0;
    }
    if (flag0){
        cout << a.size() << "\n";
        for (auto elem : a)
            cout << elem << " ";
        cout << "\n";
        return 0;
    }

    int sh = -1;
    for (int shift = 1; shift < n; ++shift){
        ll all = A + shift * a.size() + D - shift * d.size();
        //cout << shift << ": " << all << "\n";
        if (!dbet.empty() && *dbet.begin() < shift + 1){
            //cout << "wtf\n";
            //cout << *ds.begin() << "!\n";
            break;
        }
        if (left > 0 && left < shift)
            break;
        if (right > 0 && right < shift)
            break;
        if (left == shift + 1 || right == shift + 1)
            continue;
        if (dbet.find(shift + 2) != dbet.end()){
            continue;
        }
        if (all + shift != n)
            continue;
        if (shift == 1){
            if (odd)
                continue;
            if ((left > 0 && left % 2 == 0) || (right > 0 && right % 2 == 0))
                continue;
        }
        sh = shift;
        break;
    }
    if (sh == -1){
        cout << "-1\n";
        return 0;
    }

    //cout << "here" << endl;
    //cout << sh << endl;
    c = s[0];
    int pt1 = 0;
    int pt2 = 0;
    vector<int> ans;
    while (pt1 < a.size() || pt2 < d.size()){
        if (c == '#'){
            ans.push_back(a[pt1] + sh);
            pt1++;
            c = '_';
            continue;
        }
        int val = d[pt2] - sh;
        val--;
        if (pt1 == 0 && pt2 == 0)
            val++;
        if (pt1 == a.size() && pt2 + 1 == d.size())
            val++;
        if (val % 2 == 1){
            ans.push_back(2);
            val -= 3;
        }
        for (int i = 0; i < val / 2; ++i){
            ans.push_back(1);
        }
        pt2++;
        c = '#';
    }

    //cout << "here2" << endl;

    cout << ans.size() << "\n";
    for (auto elem : ans)
        cout << elem << " ";
    cout << "\n";

}