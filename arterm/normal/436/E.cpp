#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#define M 300300
#define INF 1000000000000000000ll

multiset<int> les, rem;
long long sum = 0;

void add(int x){
    if (!rem.empty() && *rem.begin() <= x){
        rem.insert(x);
    }
    else{
        les.insert(x);
        sum += x;
    }
}

void erase(int x){
    multiset<int>::iterator lx = les.find(x), rx = rem.find(x);
    if (lx != les.end()){
        les.erase(lx);
        sum -= x;
    }
    else if (rx != rem.end()){
        rem.erase(rx);
    }
}

void fit(int size){
    while ((int) les.size() < size){
        les.insert(*rem.begin());
        sum += *rem.begin();
        rem.erase(rem.begin());
    }
    while ((int) les.size() > size){
        multiset<int>::iterator it = les.end();
        --it;
        sum -= *it;
        rem.insert(*it);
        les.erase(it);
    }
}
        
int n, a[M], b[M], w, u[M], num[M];
pair<pair<int, int>, int > p[M];
pair<int, int> temp[M];

void read(){
    cin >> n >> w;
    for (int i = 0; i < n; ++i){
        cin >> p[i].first.second >> p[i].first.first;
        p[i].second = i;
    }
    
    sort(p, p + n);
    
    for (int i = 0; i < n; ++i){
        a[i] = p[i].first.second;
        b[i] = p[i].first.first;
        num[i] = p[i].second;
    }
}

void kill(){
    long long ans = INF, get = 0;
    int best = 0;
    for (int i = 0; i < n; ++i)
        add(a[i]);
    
    for (int i = 0; i <= n && i <= w; ++i){
        if (w - i <= n){
            fit(w - i);
            if (ans > get + sum){
                ans = get + sum;
                best = i;
            }
        }
        
        if (i < n){
            erase(a[i]);
            add(b[i] - a[i]);
            get += a[i];
        }
    }
    
    cout << ans << "\n";
    
    for (int i = 0; i < best; ++i)
        u[num[i]] = 1;
    
    for (int i = 0; i < best; ++i)
        temp[i] = make_pair(b[i] - a[i], num[i]);
        
    for (int i = best; i < n; ++i)
        temp[i] = make_pair(a[i], num[i]);
        
    sort(temp, temp + n);
    
    for (int i = 0; i < w - best; ++i){
        int x = temp[i].second;
        ++u[x];
    }
    
    for (int i = 0; i < n; ++i)
        cout << u[i];
    
    cout << "\n";
        
    
}


int main(){
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    kill();
    
    return 0;
}