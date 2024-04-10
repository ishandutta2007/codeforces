#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

struct fenwick {
    int n;
    vector<li> a;
    vector<int> arr;
    
    fenwick(int n): n(n), a(n), arr(n) {}
    
    void change(int index, int value) {
        change_by(index, value - arr[index]);
        arr[index] = value;
    }
    
    void change_by(int i, int value) {
        for (; i < n; i = (i | (i + 1)))
            a[i] += value;
    }
    
    li query(int l, int r) {
        return query(r) - query(l - 1);
    }
    
    li query(int i) {
        if (i < 0) return 0;
        
        li ans = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            ans += a[i];
        return ans;
    }
};

struct query {
    int type;
    union { int l; int index; };
    union { int r; int value; };
};

void solve(bool read) {
    query q;
    q.type = 1;
    
    int n, nq;
    if (read)
        cin >> n >> nq;
    else {
        n = rand() % 5 + 1, nq = rand() % 5 + 1;
        //printf("%d %d\n", n, nq);
        n = nq = 100000;
    }
    
    vector<set<int>> occ(n + 1);
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        if (read)
            cin >> arr[i];
        else {
            arr[i] = rand() % n + 1;
            //printf("%d ", arr[i]);
        }
        occ[arr[i]].insert(i);
    }
    //if (!read) printf("\n");
    
    vector<query> queries;
    for (int i = 0; i < nq; i++) {
        int type, a, b;
        if (read)
            cin >> type >> a >> b;
        else {
            type = rand() % 2 + 1, a = rand() % n + 1, b = rand() % n + 1;
            if (type == 2 && a > b) swap(a, b);
            //printf("%d %d %d\n", type, a, b);
        }
        
        if (type == 1)
            a--;
        else {
            a--; b--;
        }
        
        queries.push_back(query { type, { a }, { b } });
    }
    
    auto state = arr;
    
    const int BLOCK_SIZE = 300;
    
    vector<li> answer(queries.size());
    for (int l = 0; l < (int)queries.size();) {
        int r = l - 1;
        
        set<int> fixed;
        
        // left index, id
        vector<vector<pair<int, int>>> to_answer(n);
        while (r + 1 < (int)queries.size() && fixed.size() <= BLOCK_SIZE) {
            r++;
            if (queries[r].type == 1) {
                fixed.insert(arr[queries[r].index]);
                fixed.insert(queries[r].value);   
            }
        }
        //printf("block %d..%d, fixed: ", l + 1, r + 1); for (int x: fixed) printf("%d ", x); printf("\n");
        
        int R = r;
        for (int r = l; r <= R; r++) {
            if (queries[r].type == 1) {
                occ[arr[queries[r].index]].erase(queries[r].index);
                occ[queries[r].value].insert(queries[r].index);
                
                arr[queries[r].index] = queries[r].value;
            }
            else {
                to_answer[queries[r].r].emplace_back(queries[r].l, r);
                //printf("\nQUERY %d\n", r);
                
                for (auto it: fixed) {
                    //printf("fixed %d query %d..%d: ", it, queries[r].l, queries[r].r); for (int x: occ[it]) printf("%d ", x); printf("\n");
                    auto it1 = occ[it].lower_bound(queries[r].r + 1);
                    if (it1 == occ[it].begin()) continue;
                    it1 = prev(it1);
                    
                    auto it2 = occ[it].lower_bound(queries[r].l);
                    if (it2 == occ[it].end()) continue;
                    
                    //printf("fixed %d -> %d add (%d %d)\n", it, *it1 - *it2, *it2, *it1);
                    answer[r] += max(*it1 - *it2, 0);
                }
            }
        }
        
        vector<int> prev_last(n + 1, -1), last(n + 1, -1);
        
        fenwick s(n);
        for (int i = 0; i < n; i++) {
            if (!fixed.count(arr[i])) {
                //printf("non fixed %d at %d\n", arr[i], i + 1);
                if (last[arr[i]] != -1) {
                    s.change(last[arr[i]], i - last[arr[i]]);
                    //printf("changed %d to %d\n", last[arr[i]] + 1, i - last[arr[i]]);
                    
                    if (prev_last[arr[i]] != -1)
                        s.change(prev_last[arr[i]], last[arr[i]] - prev_last[arr[i]]);
                }
                
                prev_last[arr[i]] = last[arr[i]];
                last[arr[i]] = i;
            }
            
            for (auto it: to_answer[i]) {
                //printf("answer %d..%d -> %lld impact\n", it.first + 1, i + 1, s.query(it.first, i));
                answer[it.second] += s.query(it.first, i);
            }
        }
        
        l = r + 1;
    }
    
#if 0
    vector<li> expected(nq);
    for (int i = 0; i < nq; i++) {
        if (queries[i].type == 2) {
            for (int x = 0; x <= n; x++) {
                int first = -1, last = -1;
                for (int j = queries[i].l; j <= queries[i].r; j++)
                    if (state[j] == x) {
                        if (first == -1) first = j;
                        last = j;
                    }
                    
                expected[i] += last - first;
            }
        }
        else {
            state[queries[i].index] = queries[i].value;
        }
    }
        
    printf("answer  : "); for (int i = 0; i < nq; i++) if (queries[i].type == 2) printf("%lld ", answer[i]); printf("\n");
    printf("expected: "); for (int i = 0; i < nq; i++) if (queries[i].type == 2) printf("%lld ", expected[i]); printf("\n");
    assert(answer == expected);
#endif

    for (int i = 0; i < nq; i++)
        if (queries[i].type == 2)
            cout << answer[i] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve(true);
    //solve(false);
    
    //while (true)
    //    solve(false);
    
    return 0;
}