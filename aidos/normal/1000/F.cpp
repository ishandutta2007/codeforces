#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n;
int a[500500];
pair< pair<int, int>, pair<int, int> > Q[500500];
int ans[500500];
int t[2000200];
void add(int v, int l, int r, int pos, int val){
    if(l == r){
        t[v] = val;
    }else{
        int mid = (l + r)>>1;
        if(pos <= mid) add(v * 2, l, mid, pos, val);
        else add(v * 2 + 1, mid+1, r, pos, val);
        t[v] = min(t[v * 2], t[v * 2+1]);
    }
}
int get(int v, int l, int r, int tl, int tr, int x){
    if(l > tr || tl > r) return 0;
    if(t[v] > x) return 0;
    if(l == r) return l;
    int mid = (l + r)/2;
    int res = get(v * 2, l, mid, tl, tr, x);
    if(res) return res;
    return get(v * 2 + 1, mid+1, r, tl, tr, x);
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++){scanf("%d", a + i);
    }
    int mx = *max_element(a, a+n)+1;
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        int l, r;scanf("%d%d", &l, &r);
        l--;
        r--;
        Q[i].first.first =r;
        Q[i].first.second=r;
        Q[i].second.first = l;
        Q[i].second.second = i;
    }
    int L = -1, R = 0;

    sort(Q, Q + q);
    int j = 0;
    add(1, 0, n, 0, (1e9));
    map<int, int> prv;
    for(int i = 0; i < n; i++){
        if(prv.count(a[i])) {
            add(1, 0, n, prv[a[i]], (int) 1e9);
            add(1, 0, n, i + 1, prv[a[i]] + 1);
        }else{
            add(1, 0, n, i + 1, 1);
        }
        prv[a[i]] = i+1;
        while(j < q && Q[j].first.first == i) {
            int l = Q[j].second.first;
            int r = Q[j].first.second;
            int id = Q[j].second.second;
            ans[id] = get(1, 0, n, l+1, r+1, l+1);
            j++;
        }
    }
    for(int i = 0; i < q; i++) {
        if(ans[i]) ans[i] = a[ans[i] - 1];
        printf("%d\n", ans[i]);
    }


	return 0;
}