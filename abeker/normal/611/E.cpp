#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 200005;

int N;
int a[5];
multiset <int> S;
int sum[10];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < 3; i++) 
        scanf("%d", a + i);
    while (N--) {
        int x;
        scanf("%d", &x);
        S.insert(x);
    }
}

int get(int val) {
    multiset <int> :: iterator it = S.upper_bound(val);
    if (it == S.begin()) return -1;
    return *(--it);
}

void remove(int val) {
    if (S.find(val) != S.end())     
        S.erase(S.find(val));
}

int solve() {
    sort(a, a + 3, greater <int> ());
    for (int i = 1; i < 8; i++) 
        for (int j = 0; j < 3; j++)
            if (i >> j & 1) sum[i] += a[j];
        
    int sol = 0;
    while (!S.empty()) {
        sol++;
        int maks = *S.rbegin(), pos = 0;
        for (int i = 1; i < 8; i++)
            if (sum[i] >= maks && (!pos || sum[i] <= sum[pos]))
                pos = i;
        if (!pos) return -1;
        remove(maks);
        if (S.empty()) break;
        
        if (pos == 6 && a[0] >= maks) 
            pos = 1;
            
        vector <int> tmp;
        for (int i = 0; i < 3; i++)
            if (!(pos >> i & 1)) tmp.push_back(a[i]);
            
        if (tmp.empty()) continue;
        if (tmp.size() == 1)
            remove(get(tmp[0]));
        else {
            int f = get(tmp[0]);
            if (f == -1) 
                remove(get(tmp[0] + tmp[1]));
            else {
                remove(f);
                if (!S.empty())
                    remove(get(tmp[1]));
            }
        }
    }
    
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}