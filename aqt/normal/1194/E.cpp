#include <bits/stdc++.h>

using namespace std;

struct event{
    int x, idx, typ;
    bool operator < (const event e) const{
        if(x == e.x){
            return typ > e.typ;
        }
        return x < e.x;
    }
};

struct line{
    int c, t, b;
    bool typ; //1 = vert
};

int N;
line arr[5005];
vector<event> e, v;
int BIT[10005];

void upd(int n, int v){
    n += 5001;
    for(int i = n; i<=10004; i+=i&-i){
        BIT[i] += v;
    }
}

int query(int n){
    n += 5001;
    int s = 0;
    for(int i = n; i>0; i-=i&-i){
        s += BIT[i];
    }
    return s;
}

long long solve(){
    sort(v.begin(), v.end());
    long long s = 0;
    for(auto ev : v){
        //cout << "type: " << ev.typ << endl;
        if(ev.typ == 0){
            long long t = query(arr[ev.idx].t) - query(arr[ev.idx].b-1);
            //cout << " " << t << endl;
            s += t*(t-1)/2;
        }
        else{
            upd(arr[ev.idx].c, ev.typ);
        }
    }
    v.clear();
    //cout << s << endl;
    return s;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2){
            swap(x1, x2);
        }
        if(y1 > y2){
            swap(y1, y2);
        }
        if(x1 == x2){
            arr[i].c = x1;
            arr[i].t = y2;
            arr[i].b = y1;
            arr[i].typ = 1;
            e.push_back({x1, i, 0});
        }
        else{
            arr[i].c = y1;
            arr[i].t = x2;
            arr[i].b = x1;
            arr[i].typ = 0;
            //e.push_back({x1, i, 1});
            //e.push_back({x2, i, -1});
        }
    }
    sort(e.begin(), e.end());
    long long ans = 0;
    for(int n = 0; n<e.size(); n++){
        for(int i = 1; i<=N; i++){
            if(arr[i].typ == 0){
                if(arr[i].b <= e[n].x && arr[i].t >= e[n].x &&
                   arr[e[n].idx].b <= arr[i].c && arr[e[n].idx].t >= arr[i].c){
                    //cout << n << " " << i << endl;
                    v.push_back({-arr[i].t, i, 1});
                    v.push_back({-arr[i].b, i, -1});
                    //cout << "coords: " << -arr[i].t << " " << -arr[i].b << endl;
                }
            }
        }
        for(int k = 0; k<n; k++){
            v.push_back({-e[k].x, e[k].idx, 0});
            //cout << "coords: " << -e[n].x << " " << e[n].x << " " << e[n].idx << endl;
        }
        ans += solve();
    }
    cout << ans << endl;
}