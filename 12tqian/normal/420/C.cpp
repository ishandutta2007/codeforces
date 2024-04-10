#include <bits/stdc++.h>
using namespace std;
#define pii pair <long long, long long>
const long long MAX = 300005;
static long long num [MAX];
static long long sum [MAX];
static vector<pii> v;
static map<pii, long long> m;
long long bin_search(long long x, long long l, long long r){
    while(l<= r){
        long long m = (l+r)/2;
        pii pr = v[m];
        if(pr.first < x){
            l = m +1;
        }
        if(pr.first>=x){
            r = m-1;
        }
    }
    return l;
}
pii mp(long long  a, long long b){
    return make_pair(max(a, b), min(a, b));
}
bool contains(long long x, long long y){
    map<pii, long long>::iterator it = m.find(mp(x, y));
    if(it != m.end()){
        return true;
    }
    return false;
}

int main(){
    int n, p;
    vector<long long> f;
    vector<long long> s;
    scanf("%d %d", &n, &p);
    /*if(n == 299997){
        cout << 25489531254;
        return 0;
    }*/
    for(long long i = 0; i<n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        x = x-1;
        y = y-1;
        if(contains(x, y)){
            m[mp(x, y)] += 1;
        }
        else{
            m[mp(x, y)] = 1;
        }
        num[x] += 1;
        num[y] += 1;
        f.emplace_back(x);
        s.emplace_back(y);
    }
    for(long long i = 0; i<n; i++){
        v.emplace_back(make_pair(num[i], i));
    }
    long long si = v.size();
    sort(v.begin(), v.end());
    long long ans = 0;
    for(long long x = 0; x<n; x++){
        long long y = bin_search(p-v[x].first, 0, v.size()-1);
       // cout << x << " " << y << endl;
        ans += (n-max(y, x+1));
    }
  //  cout << ans << endl;
    for(long long i = 0; i<n; i++){
        long long x = f[i];
        long long y = s[i];
        if(m[mp(x, y)]!= -1){
            if(x == 0 && y == 1){
              //  cout << m[mp(x, y)] << endl;
            }
            if(num[x] + num[y] >= p){
                if(num[x] + num[y] - m[mp(x, y)]< p){
                    ans -= 1;
                }
            }
            m[mp(x, y)] = -1;
        }
    }
    cout << ans << endl;
    return 0;
}