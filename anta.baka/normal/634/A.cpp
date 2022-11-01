#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    list<int> a, b;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(num)
            a.pb(num);
    }
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(num)
            b.pb(num);
    }
    while(a.front() != b.front()) {
        a.pb(a.front());
        a.pop_front();
    }
    if(a == b)
        cout << "YES";
    else
        cout << "NO";
}