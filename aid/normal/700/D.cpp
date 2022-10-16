#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 5, K = 300, MAXB = (MAXN + K - 1) / K;
int a[MAXN], l[MAXN], r[MAXN], ans[MAXN], c[MAXN], cnt[K];
char isBig[MAXN];
vector< pair<int, int> > qb[MAXB];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> l[i] >> r[i];
        l[i]--;
        qb[l[i] / K].push_back(make_pair(r[i], i));
    }
    int b = (n + K - 1) / K;
    for(int i = 0; i < b; i++) {
        sort(qb[i].begin(), qb[i].end());
        int k = i * K;
        vector<int> big;
        for(size_t j = 0; j < qb[i].size(); j++) {
            int id = qb[i][j].second;
            while(k < r[id]) {
                if(c[a[k]] < K)
                    cnt[c[a[k]]]--;
                c[a[k]]++;
                if(c[a[k]] == K) {
                    big.push_back(a[k]);
                    isBig[a[k]] = true;
                }
                if(c[a[k]] < K)
                    cnt[c[a[k]]]++;
                k++;
            }
            int ll = i * K;
            while(ll < l[id]) {
                if(!isBig[a[ll]])
                    cnt[c[a[ll]]]--;
                c[a[ll]]--;
                if(!isBig[a[ll]])
                    cnt[c[a[ll]]]++;
                ll++;
            }
            vector< pair<int, int> > v;
            for(int ii = 1; ii < K; ii++)
                if(cnt[ii])
                    v.push_back(make_pair(ii, cnt[ii]));
            for(size_t ii = 0; ii < big.size(); ii++)
                if(c[big[ii]])
                    v.push_back(make_pair(c[big[ii]], 1));
            sort(v.begin(), v.end());
            queue< pair<int, int> > q0, q1;
            for(size_t ii = 0; ii < v.size(); ii++)
                q0.push(v[ii]);
            while(true) {
                pair<int, int> p0;
                if(!q0.empty() && (q1.empty() || q0.front() < q1.front())) {
                    p0 = q0.front();
                    q0.pop();
                }
                else {
                    p0 = q1.front();
                    q1.pop();
                }
                if(p0.second > 1) {
                    ans[id] += p0.first * 2 * (p0.second / 2);
                    q1.push(make_pair(2 * p0.first, p0.second / 2));
                    p0.second = (p0.second & 1);
                }
                if(p0.second) {
                    if(q0.empty() && q1.empty())
                        break;
                    int p1;
                    if(!q0.empty() && (q1.empty() || q0.front() < q1.front())) {
                        p1 = q0.front().first;
                        q0.front().second--;
                        if(!q0.front().second)
                            q0.pop();
                    }
                    else {
                        p1 = q1.front().first;
                        q1.front().second--;
                        if(!q1.front().second)
                            q1.pop();
                    }
                    ans[id] += p0.first + p1;
                    q1.push(make_pair(p0.first + p1, 1));
                }
            }
            while(ll > i * K) {
                ll--;
                if(!isBig[a[ll]])
                    cnt[c[a[ll]]]--;
                c[a[ll]]++;
                if(!isBig[a[ll]])
                    cnt[c[a[ll]]]++;
            }
        }
        for(int j = 0; j < n; j++) {
            c[a[j]] = 0;
            isBig[a[j]] = false;
        }
        for(int j = 0; j < K; j++)
            cnt[j] = 0;
    }
    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';
    return 0;
}