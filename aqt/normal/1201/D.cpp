#include <bits/stdc++.h>

using namespace std;

int N, M, K, Q;
long long lft[200005], rht[200005];
vector<int> cmp;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(false);
    cin >> N >> M >> K >> Q;
    fill(lft+1, lft+1+N, INT_MAX);
    lft[1] = rht[1] = 1;
    long long lim = 1;
    for(int i = 1; i<=K; i++){
        long long x, y;
        cin >> x >> y;
        lim = max(lim, x);
        lft[x] = min(lft[x], y);
        rht[x] = max(rht[x], y);
    }
    while(Q--){
        int n;
        cin >> n;
        cmp.push_back(n);
    }
    sort(cmp.begin(), cmp.end());
    long long ledge = 2*(rht[1]-lft[1]), redge = rht[1]-lft[1];
    int prel = lft[1], prer = rht[1];
    for(int i = 2; i<=N; i++){
        if(lft[i] != INT_MAX){
            long long templ = LLONG_MAX, tempr = LLONG_MAX;
            int bll = ((prel >= cmp.front()) ? *(--lower_bound(cmp.begin(), cmp.end(), prel+1)) : 0);
            int blr = ((prel <= cmp.back()) ? *(lower_bound(cmp.begin(), cmp.end(), prel)) : 0);
            int brl = ((prer >= cmp.front()) ? *(--lower_bound(cmp.begin(), cmp.end(), prer+1)) : 0);
            int brr = ((prer <= cmp.back()) ? *(lower_bound(cmp.begin(), cmp.end(), prer)) : 0);
            if(bll){
                tempr = min(tempr, abs(lft[i] - bll) + abs(prel - bll) + ledge);
                templ = min(templ, abs(rht[i] - bll) + abs(prel - bll) + ledge);
            }
            if(blr){
                tempr = min(tempr, abs(lft[i] - blr) + abs(prel - blr) + ledge);
                templ = min(templ, abs(rht[i] - blr) + abs(prel - blr) + ledge);
            }
            if(brl){
                tempr = min(tempr, abs(lft[i] - brl) + abs(prer - brl) + redge);
                templ = min(templ, abs(rht[i] - brl) + abs(prer - brl) + redge);
            }
            if(brr){
                tempr = min(tempr, abs(lft[i] - brr) + abs(prer - brr) + redge);
                templ = min(templ, abs(rht[i] - brr) + abs(prer - brr) + redge);
            }
            templ += rht[i] - lft[i], tempr += rht[i] - lft[i];
            swap(templ, ledge), swap(tempr, redge);
            prel = lft[i], prer = rht[i];
            //cout << i << " " << ledge << " " << redge << endl;
        }
    }
    cout << min(ledge, redge) + lim - 1 << "\n";
}