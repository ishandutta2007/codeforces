#include <bits/stdc++.h>

using namespace std;

int n, a, b, k, f;
string s1[300], s2[300];
map<string, int> re;
int dif;
int cnta[600][600], cntb[600][600];
int ret;

void adda(int u, int v) {
    if(u > v) swap(u, v);
    cnta[u][v]++;
}

void addb(int u, int v) {
    if(u > v) swap(u, v);
    cntb[u][v]++;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> a >> b >> k >> f;
    for(int i = 0; i < n; i++) {
        cin >> s1[i] >> s2[i];
        re[s1[i]];
        re[s2[i]];
    }
    for(auto it = re.begin(); it != re.end(); it++)
        it->second = dif++;
    adda(re[s1[0]], re[s2[0]]);
    ret = a;
    for(int i = 1; i < n; i++)
        if(re[s2[i - 1]] == re[s1[i]]) {
            addb(re[s1[i]], re[s2[i]]);
            ret += b;
        } else {
            adda(re[s1[i]], re[s2[i]]);
            ret += a;
        }
    multiset<int> q;
    for(int i = 0; i < dif; i++)
        for(int j = i + 1; j < dif; j++) {
            q.insert(cnta[i][j] * a + cntb[i][j] * b);
            if(q.size() == k + 1)
                q.erase(q.begin());
        }
    int sum = ret;
    for(auto it = q.rbegin(); it != q.rend(); it++) {
        sum += f - *it;
        ret = min(ret, sum);
    }
    cout << ret;
}