#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
int used[1000005];
int used1[1000005];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set < char > t = {'a', 'e', 'i', 'o', 'u'};
    vector < pair < pair < int, int >, string > > f;
    vector < string > Q;
    vector < pair < int, int > > a;
    for (int i = 1; i <= n; ++i){
        string s;
        cin >> s;
        int cnt = 0;
        char last = 'a';
        for (auto c : s){
            if (t.find(c) != t.end()){
                cnt++;
                last = c;
            }
        }
        f.push_back({{cnt, last - 'a'}, s});
    }
    sort(f.begin(), f.end());
    for (auto key : f){
        a.push_back(key.first);
        Q.push_back(key.second);
    }
    vector < int > two;
    for (int i = 1; i < (int)a.size(); ++i){
        if (used[i - 1] == 1) continue;
        if (a[i] == a[i - 1]){
            used[i] = 1;
            used[i - 1] = 1;
            two.push_back(i - 1);
        }
    }
    vector < pair < int, int > > a1;
    vector < string > Q1;
    for (int i = 0; i < (int)a.size(); ++i){
        if (used[i] == 1) continue;
        a1.push_back(a[i]);
        Q1.push_back(Q[i]);
    }
    vector < int > one;
    for (int i = 1; i < (int)a1.size(); ++i){
        if (used1[i - 1] == 1) continue;
        if (a1[i].first == a1[i - 1].first){
            used1[i] = 1;
            used1[i - 1] = 1;
            one.push_back(i - 1);
        }
    }
    int n1 = one.size(), n2 = two.size();
    vector < pair < pair < string, string >, pair < string, string > > > out;
    if (n1 <= n2){
        for (int i = 0; i < n1; ++i){
            out.push_back({{Q1[one[i]], Q1[one[i] + 1]}, {Q[two[i]], Q[two[i] + 1]}});
        }
        for (int i = n1; i < n2; i += 2){
            if (i + 1 >= n2) continue;
            out.push_back({{Q[two[i]], Q[two[i] + 1]}, {Q[two[i + 1]], Q[two[i + 1] + 1]}});
        }
    }
    else{
        for (int i = 0; i < n2; ++i){
            out.push_back({{Q1[one[i]], Q1[one[i] + 1]}, {Q[two[i]], Q[two[i] + 1]}});
        }
    }
    cout << out.size() << '\n';
    for (auto key : out){
        cout << key.X.X << " " << key.Y.X << '\n';
        cout << key.X.Y << " " << key.Y.Y << '\n';
    }
    return 0;
}