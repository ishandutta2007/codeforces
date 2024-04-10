#include <bits/stdc++.h>

using namespace std;

struct query{
    int t, l, r, id;
    bool operator < (query q) const{
        if(t/2000 == q.t/2000){
            if(l/2000 == q.l/2000){
                if(r == q.r){
                    return l < q.l;
                }
                return r < q.r;
            }
            return l/2000 < q.l/2000;
        }
        return t/2000 < q.t/2000;
    }
};

int N, Q, M, K, B = 2000;
int arr[100005];
query qu[100005];
pair<int, int> mod[100005];
int cnt[200005];
int fre[200005];
int ans[100005];
vector<int> cmp;
stack<int> stk;

int getidx(int v){
    return lower_bound(cmp.begin(), cmp.end(), v) - cmp.begin()+1;
}

void add(int n){
    cnt[fre[n]]--;
    fre[n]++;
    cnt[fre[n]]++;
}

void rem(int n){
    cnt[fre[n]]--;
    fre[n]--;
    cnt[fre[n]]++;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        cmp.push_back(arr[i]);
    }
    int c = 0;
    for(int q = 1; q<=Q; q++){
        int c;
        cin >> c;
        if(c == 2){
            M++;
            cin >> mod[M].first >> mod[M].second;
            cmp.push_back(mod[M].second);
        }
        else{
            K++;
            cin >> qu[K].l >> qu[K].r;
            qu[K].t = M;
            qu[K].id = K;
        }
    }
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    for(int i = 1; i<=N; i++){
        arr[i] = getidx(arr[i]);
    }
    for(int i = 1; i<=M; i++){
        mod[i].second = getidx(mod[i].second);
    }
    sort(qu+1, qu+1+K);
    int r = 0, l = 1, q = 0;
    for(int k = 1; k<=K; k++){
        while(r < qu[k].r){
            r++;
            add(arr[r]);
        }
        while(r > qu[k].r){
            rem(arr[r]);
            r--;
        }
        while(l > qu[k].l){
            l--;
            add(arr[l]);
        }
        while(l < qu[k].l){
            rem(arr[l]);
            l++;
        }
        while(q < qu[k].t){
            q++;
            bool b = (mod[q].first <= r && mod[q].first >= l);
            if(b){
                rem(arr[mod[q].first]);
            }
            stk.push(arr[mod[q].first]);
            arr[mod[q].first] = mod[q].second;
            if(b){
                add(arr[mod[q].first]);
            }
        }
        while(q > qu[k].t){
            bool b = (mod[q].first <= r && mod[q].first >= l);
            if(b){
                rem(arr[mod[q].first]);
            }
            arr[mod[q].first] = stk.top();
            stk.pop();
            if(b){
                add(arr[mod[q].first]);
            }
            q--;
        }
        for(int n = 1; n<=N; n++){
            if(!cnt[n]){
                ans[qu[k].id] = n;
                break;
            }
        }
    }
    for(int k = 1; k<=K; k++){
        cout << ans[k] << "\n";
    }
}