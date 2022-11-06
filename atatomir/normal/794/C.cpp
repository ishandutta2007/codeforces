#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 300011

int n, i, step, done, c1, c2, pos;
string s;
vector<char> aux;
deque<char> mini, maxi;

char ans[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    cin >> s;
    for (auto e : s) aux.pb(e);
    sort(aux.begin(), aux.end());
    for (auto e : aux) mini.pb(e);

    aux.clear();
    cin >> s;
    for (auto e : s) aux.pb(e);
    sort(aux.begin(), aux.end());
    for (auto e : aux) maxi.pb(e);

    step = 0;
    n = s.size();

    c1 = (n + 1) / 2;
    c2 = n - c1;
    for (i = c1 + 1; i <= n; i++) mini.pop_back();
    for (i = c2 + 1; i <= n; i++) maxi.pop_front();

    mini.push_back('z');
    maxi.push_front('a');

    while (done < n && mini.front() < maxi.back()) {
        if (step == 0) {
            ans[++pos] = mini.front();
            mini.pop_front();
        } else {
            ans[++pos] = maxi.back();
            maxi.pop_back();
        }

        step ^= 1;
        done++;
    }

    mini.pop_back();
    maxi.pop_front();

    pos = n;
    mini.push_front('a');
    maxi.push_back('z');

    while (done < n) {
        if (step == 0) {
            ans[pos--] = mini.back();
            mini.pop_back();
        } else {
            ans[pos--] = maxi.front();
            maxi.pop_front();
        }

        step ^= 1;
        done++;
    }

    for (i = 1; i <= n; i++) cout << ans[i];

    return 0;
}