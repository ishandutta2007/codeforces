#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200 * 1000 + 5, MAXX = 10 * 1000 + 5;
int s[MAXN], r[MAXN], maxr[MAXX];

bool bad(const pair<int, int> &a, const pair<int, int> &b,
         const pair<int, int> &c) {
    return (long long)a.second * c.first *
        (a.first - b.first) * (b.second - c.second) -
        (long long)a.first * c.second *
        (a.second - b.second) * (b.first - c.first) < 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i] >> r[i];
        maxr[s[i]] = max(maxr[s[i]], r[i]);
    }
    int rr = 0;
    vector< pair<int, int> > ch;
    for(int i = MAXX - 1; i >= 0; i--)
        if(maxr[i] > rr) {
            while(ch.size() > 1 && bad(ch[(int)ch.size() - 2], ch.back(),
                                       make_pair(i, maxr[i])))
                ch.pop_back();
            ch.push_back(make_pair(i, maxr[i]));
            rr = maxr[i];
        }
    for(int i = 0; i < n; i++)
        if(binary_search(ch.begin(), ch.end(), make_pair(s[i], r[i]),
                         greater< pair<int, int> >()))
            cout << i + 1 << ' ';
    cout << '\n';
    return 0;
}