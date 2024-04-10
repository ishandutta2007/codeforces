#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int n, t[MAXN], T;

typedef pair<int,int> pii;

multiset<pii> l;
int e;

#define fir first
#define sec second

#define mp make_pair

int main() {
    #ifdef Fekete
        freopen("barik.in", "r", stdin);
        freopen("barik.out", "w", stdout);
    #else

    #endif // Fekete

//    ios::sync_with_stdio(false);
  //  cin.tie(nullptr);


    scanf("%d%d", &n, &T);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
//        cout<<i<<" !!!\n";
        if (T-i>=1){
            l.insert(mp(t[i] - i,1-i));
        }
        while(l.size() > 0 && (*l.rbegin()).fir >= T - i) {
            auto p=*l.rbegin();
//            cout<<"ers L :: "<<p.fir<<" "<<p.sec<<"\n";
            l.erase(l.find(p));
        }
        ans = max(ans, (int)l.size());
    }
    cout << ans;
}