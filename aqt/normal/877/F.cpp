#include <bits/stdc++.h>

using namespace std;

struct query{
    int l, r, id;
    bool operator < (query q) const{
        if(l/300 == q.l/300){
            if(r == q.r){
                return l < q.l;
            }
            return r < q.r;
        }
        return l/300 < q.l/300;
    }
};

int N, Q;
long long K;
long long pre[100005];
long long out[100005];
long long fre[100005];
long long aft[100005], bef[100005];
vector<long long> cmp;
query arr[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for(int i = 1; i<=N; i++){
        cin >> pre[i];
        if(pre[i] == 2){
            pre[i] = -1;
        }
    }
    cmp.push_back(0);
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        pre[i] *= n;
        pre[i] += pre[i-1];
        cmp.push_back(pre[i]);
    }
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    for(int i = 0; i<cmp.size(); i++){
        bef[i] = aft[i] = -1;
        if(*lower_bound(cmp.begin(), cmp.end(), cmp[i]-K) == cmp[i]-K){
            bef[i] = lower_bound(cmp.begin(), cmp.end(), cmp[i]-K) - cmp.begin();
        }
        if(*lower_bound(cmp.begin(), cmp.end(), cmp[i]+K) == cmp[i]+K){
            aft[i] = lower_bound(cmp.begin(), cmp.end(), cmp[i]+K) - cmp.begin();
        }
    }
    cin >> Q;
    for(int i = 0; i<=N; i++){
        pre[i] = lower_bound(cmp.begin(), cmp.end(), pre[i]) - cmp.begin();
    }
    for(int q = 1; q<=Q; q++){
        cin >> arr[q].l >> arr[q].r;
        arr[q].id = q;
    }
    sort(arr+1, arr+1+Q);
    long long ans = 0;
    int l = 0, r = -1;
    for(int q = 1; q<=Q; q++){
        //cout << " " << arr[q].l << " " << arr[q].r << endl;
        while(r < arr[q].r){
            ++r;
            if(bef[pre[r]] != -1){
                ans += fre[bef[pre[r]]];
            }
            fre[pre[r]]++;
        }
        //cout << ans << endl;
        while(l > arr[q].l-1){
            --l;
            if(aft[pre[l]] != -1){
                ans += fre[aft[pre[l]]];
            }
            fre[pre[l]]++;
        }
        //cout << ans << endl;
        while(l < arr[q].l-1){
            fre[pre[l]]--;
            if(aft[pre[l]] != -1){
                ans -= fre[aft[pre[l]]];
            }
            l++;
        }
        //cout << ans << endl;
        while(r > arr[q].r){
            fre[pre[r]]--;
            if(bef[pre[r]] != -1){
                ans -= fre[bef[pre[r]]];
            }
            r--;
        }
        //cout << ans << endl;
        out[arr[q].id] = ans;
    }
    for(int q = 1; q<=Q; q++){
        cout << out[q] << "\n";
    }
}