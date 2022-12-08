#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll,ll>

using namespace std;

struct Seg {
    ll n;
    vector<ll> seg;
    Seg(ll n): n(n) { seg.resize(2*n); }
    void update(ll idx, ll val) {
        idx += n;
        seg[idx] = val;
        for(idx >>= 1; idx; idx >>= 1) {
            seg[idx] = seg[idx<<1] + seg[(idx<<1)|1];
        }
    }
    ll query(ll a, ll b) {
        ll res = 0;
        for(a += n, b += n; a < b; a >>= 1, b >>= 1) {
            if(a & 1) {
                res += seg[a++];
            }
            if(b & 1) {
                res += seg[--b];
            }
        }
        return res;
    }
};

struct Line {
    ll x1, y1, x2, y2;
};

ll get_idx(vector<ll> &sorted, ll val) {
    ll l = 0, r = sorted.size() - 1;
    while(l < r) {
        ll mid = (l+r)/2;
        if(sorted[mid] < val) {
            l = mid + 1;
        } else if(sorted[mid] > val) {
            r = mid - 1;
        } else {
            return mid;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<Line> lines(n);
    set<ll> ys;
    set<ll> xs;
    for(ll i = 0; i < n; i ++) {
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        if(x1 > x2) { swap(x1, x2); }
        if(y1 > y2) { swap(y1, y2); }

        // store for after compression:
        lines[i] = {x1,y1,x2,y2};

        // for coordinate compression:
        xs.insert(x1); xs.insert(x2);
        ys.insert(y1); ys.insert(y2);
        ys.insert(y1+1); ys.insert(y2+1);
    }
    
    // coordinate compression
    ll size_x = xs.size();
    ll size_y = ys.size();
    vector<ll> xindexed(size_x);
    vector<ll> yindexed(size_y);
    ll idx = 0;
    for(ll x : xs) { xindexed[idx++] = x; }
    idx = 0;
    for(ll y : ys) { yindexed[idx++] = y; }
    // ~~~~~~~

    vector<vector<ll>> starts(size_x); // starts of horizontal lines
    vector<vector<ll>> ends(size_x); // ends[coord]: ends of horizontal lines at 
    vector<vector<pi>> vertical(size_x); // difs in vertical lines of specific x
    for(ll i = 0; i < n; i ++) {
        Line l = lines[i];
        if(l.y1 == l.y2) {
            ll yi = get_idx(yindexed,l.y1);
            starts[get_idx(xindexed,l.x1)].push_back(yi);
            ends[get_idx(xindexed,l.x2)].push_back(yi);
        } else {
            ll xi = get_idx(xindexed,l.x1);
            vertical[xi].push_back({get_idx(yindexed,l.y1),1});
            vertical[xi].push_back({get_idx(yindexed,l.y2+1),-1});
        }
    }
    Seg black(size_y+1);
    vector<ll> lst(size_y);
    vector<ll> cnt(size_y);
    ll total = 0;
    for(ll xi = 0; xi < size_x; xi ++) {
        // updating starts:
        for(ll yi : starts[xi]) {
            cnt[yi] ++;
            if(cnt[yi] == 1) {
                lst[yi] = xindexed[xi];
                black.update(yi,1);
            }
        }
        // updating total:
        if(vertical[xi].size()) { 
            ll curr_lines = 0;
            sort(vertical[xi].begin(),vertical[xi].end());
            ll last_y = vertical[xi][0].first;
            ll curr_s;
            bool in_line = false;
            for(pi P : vertical[xi]) {
                ll yi = P.first;
                if(last_y != yi) {
                    if(!curr_lines) {
                        if(in_line) {
                            in_line = false;
                            total += yindexed[last_y-1] - yindexed[curr_s] + 1;
                            total -= black.query(curr_s,last_y);
                        }
                    } else if(!in_line) {
                        in_line = true;
                        curr_s = last_y;
                    }
                    last_y = yi;
                }
                curr_lines += P.second;
            }
            total += yindexed[last_y-1] - yindexed[curr_s] + 1;
            total -= black.query(curr_s,last_y);
        }
        // updating ends:
        for(ll yi : ends[xi]) {
            cnt[yi] --;
            if(cnt[yi] == 0) {
                total += xindexed[xi] - lst[yi] + 1;
                black.update(yi,0);
            }
        }
    }
    cout << total;
    return 0;
}