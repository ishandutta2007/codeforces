#include <bits/stdc++.h>

using namespace std;

int R, C, N, K;
vector<int> v[3005];
int temp[3005];
int lft[3005], rht[3005];
vector<int> idx;
deque<int>dq;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C >> N >> K;
    for(int i= 1; i<=N; i++){
        int r, c;
        cin >> r >> c;
        v[r].push_back(c);
    }
    temp[0] = 100;
    long long ans = 1LL*(R)*(R+1)/2*(C)*(C+1)/2;
    for(int p = 1; p<=R; p++){
        for(int q = p; q<=R; q++){
            for(int k : v[q]){
                temp[k]++;
            }
        }
        long long cnt = 0;
        int lst = 0;
        dq.push_back(0);
        for(int i = 1; i<=C; i++){
            if(temp[i]){
                lft[i] = lst;
                rht[lst] = i;
                lst = i;
                for(int j = 1; j<=temp[i]; j++){
                    dq.push_back(i);
                }
                while(dq.size() > K){
                    dq.pop_front();
                }
            }
            cnt += i-dq.front();
        }
        dq.clear();
        //cout << p << " " << cnt << endl;
        rht[lst] = C+1;
        lft[0] = 0;
        rht[C+1] = C+1;
        for(int q = R; q>=p; q--){
            //cout << " " << q << " " << cnt << endl;
            ans -= cnt;
            for(int k : v[q]){
                //cout << "ping1" << endl;
                int r = k, l = k;
                int sum = temp[k];
                while(sum < K){
                    l = lft[l];
                    sum += temp[l];
                }
                sum -= temp[k];
                //cout << "ping1.5" << endl;
                for(; r<=C && l<=k; r = rht[r]){
                    sum += temp[r];
                    while(sum-temp[l] >= K){
                        sum -= temp[l];
                        l = rht[l];
                    }
                    idx.push_back(l);
                }
                //cout << "ping2" << endl;
                temp[k]--;
                r = k, l = k;
                sum = temp[k];
                while(sum < K){
                    l = lft[l];
                    sum += temp[l];
                }
                sum -= temp[k];
                for(int c = 0; r<=C && l<=k && c<idx.size(); r = rht[r], c++){
                    sum += temp[r];
                    while(sum-temp[l] >= K){
                        sum -= temp[l];
                        l = rht[l];
                    }
                    //cout << "bling: " << idx[c] << " " << l << " " << rht[r] << " " << r << endl;
                    cnt += (rht[r]-r)*(idx[c]-l);
                }
                //cout << "ping3" << endl;
                if(!temp[k]){
                    lft[rht[k]] = lft[k];
                    rht[lft[k]] = rht[k];
                }
                idx.clear();
            }
        }
    }
    cout << ans << endl;
}