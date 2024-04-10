#include <bits/stdc++.h>

using namespace std;

typedef long long li;

const li INF = 1e18;

vector<char> eventUsed;
vector<int> collected;

pair<li, int> minp(pair<li, int> a, pair<li, int> b)
{
    if (a.first <= b.first)
        return a;
    else
        return b;
}

struct segtree
{
    // first unused index
    int n;
    vector<li> subMin;
    vector<int> nUsed;
    vector<pair<li, int>> minIndex;
    vector<vector<int>> events;
    
    segtree(int n): n(n), subMin(n * 4, INF), nUsed(n * 4), minIndex(n * 4, make_pair(INF - 1, 0)), events(n * 4) { build(0, 0, n - 1); }
    
    void build(int t, int l, int r)
    {
        if (l == r)
        {
            minIndex[t].second = l;
            return;
        }
        
        int m = (l + r) / 2;
        build(t * 2 + 1, l, m);
        build(t * 2 + 2, m + 1, r);
        minIndex[t].second = minIndex[t * 2 + 1].second;
    }
    
    void set(int index) { return set(0, 0, n - 1, index); }
    
    void set(int t, int l, int r, int index)
    {
        if (l == r)
        {
            nUsed[t] = 1;
            minIndex[t].first = INF;
            return;
        }
        
        int m = (l + r) / 2;
        if (index <= m)
            set(t * 2 + 1, l, m, index);
        else
            set(t * 2 + 2, m + 1, r, index);
        
        nUsed[t] = nUsed[t * 2 + 1] + nUsed[t * 2 + 2];
        minIndex[t] = minp(minIndex[t * 2 + 1], minIndex[t * 2 + 2]);
        if (minIndex[t].first < INF) minIndex[t].first = min(minIndex[t].first, subMin[t]);
        
        if (nUsed[t] == r - l + 1)
            minIndex[t].first = INF;
        //printf("%d..%d: min index %lld %d\n", l, r, minIndex[t].first, minIndex[t].second);
    }
    
#if 0
    pair<li, int> getMinUnused(int t, int l, int r, int x, int y)
    {
        if (x > r || y < l) return make_pair(INF, -1);
        
        if (l >= x && r <= y)
            return tree[t];
        
        int m = (l + r) / 2;
        
        return minp(getFirstUnused(t * 2 + 1, l, m, x, y), getFirstUnused(t * 2 + 2, m + 1, r, x, y));
    }
    
    int getFirstUnused(int x, int y) { return getFirstUnused(0, 0, n - 1, x, y); }
#endif
    
    void putEvent(int t, int l, int r, int x, int y, int index)
    {
        if (x > r || y < l) return;
        
        if (l >= x && r <= y)
        {
            events[t].push_back(index);
            return;
        }
        
        int m = (l + r) / 2;
        putEvent(t * 2 + 1, l, m, x, y, index);
        putEvent(t * 2 + 2, m + 1, r, x, y, index);
    }
    
    void putSubMin(int t, int l, int r, int x, int y, li sm)
    {
        //printf("sub min %d..%d %lld\n", x, y, sm);
        if (x > r || y < l) return;
        
        if (l >= x && r <= y)
        {
            subMin[t] = min(subMin[t], sm);
            if (minIndex[t].first < INF) minIndex[t].first = min(minIndex[t].first, subMin[t]);
            return;
        }
        
        int m = (l + r) / 2;
        putSubMin(t * 2 + 1, l, m, x, y, sm);
        putSubMin(t * 2 + 2, m + 1, r, x, y, sm);
        minIndex[t] = minp(minIndex[t * 2 + 1], minIndex[t * 2 + 2]);
        if (minIndex[t].first < INF) minIndex[t].first = min(minIndex[t].first, subMin[t]);
    }
    
    void putSubMin(int x, int y, li sm) { putSubMin(0, 0, n - 1, x, y, sm); }
    
    void putEvent(int x, int y, int index) { putEvent(0, 0, n - 1, x, y, index); eventUsed.resize(max((int)eventUsed.size(), index + 1)); }
    
    void collectEvents(int t, int l, int r, int index)
    {
        for (int x: events[t])
            if (!eventUsed[x])
            {
                eventUsed[x] = true;
                collected.push_back(x);
            }
            
        events[t].clear();
        
        if (l == r) return;
        
        int m = (l + r) / 2;
        if (index <= m)
            collectEvents(t * 2 + 1, l, m, index);
        else
            collectEvents(t * 2 + 2, m + 1, r, index);
    }
    
    vector<int> collectEvents(int index)
    {
        collected.clear();
        collectEvents(0, 0, n - 1, index);
        return collected;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q, start;
    cin >> n >> q >> start;
    start--;
    
    vector<vector<int>> e(n);
    
    vector<vector<tuple<int, int, int>>> segGo(n);
    
    segtree s(n);
    vector<pair<int, int>> events;
    
    for (int i = 0; i < q; i++)
    {
        int t, v, u;
        cin >> t >> v >> u;
        v--; u--;
        
        if (t == 1)
        {
            int w;
            cin >> w;
            
            segGo[v].emplace_back(u, u, w);
        }
        else
        {
            int l = u, r, w;
            cin >> r >> w;
            r--;
            
            if (t == 2)
            {
                // v -> [l, r]
                segGo[v].emplace_back(l, r, w);
            }
            else
            {
                // [l, r] -> v
                s.putEvent(l, r, events.size());
                events.emplace_back(v, w);
            }
        }
    }
    
    vector<char> used(n, false);
    s.putSubMin(start, start, 0);
    
    vector<li> dist(n, -1);
    
    for (int i = 0; i < n; i++)
    {
        int index = s.minIndex[0].second;
        li value = s.minIndex[0].first;
        if (value >= INF - 1) break;
        
        //printf("get to %d in %lld\n", index + 1, value);
        dist[index] = value;
        
        s.set(index);
        
        for (tuple<int, int, int> x: segGo[index])
        {
            int l = get<0>(x);
            int r = get<1>(x);
            int w = get<2>(x);
            
            s.putSubMin(l, r, value + w);
        }
        
        vector<int> collected = s.collectEvents(index);
        for (int eventIndex: collected)
        {
            pair<int, int> event = events[eventIndex];
            int v = event.first, w = event.second;
            s.putSubMin(v, v, value + w);
        }
    }
    
    for (int i = 0; i < n; i++)
        cout << dist[i] << ' ';
    cout << '\n';
    
    return 0;
}