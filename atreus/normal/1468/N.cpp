#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 10;

bool solve(){
    int c1, c2, c3;
    int a1, a2, a3, a4, a5;
    cin >> c1 >> c2 >> c3 >> a1 >> a2 >> a3 >> a4 >> a5;
    c1-= a1, c2-= a2, c3-= a3;
    if(c1 < 0 || c2 < 0 || c3 < 0)
	return 0;
    int x = min(c1, a4);
    c3-= a4-x;
    x = min(c2, a5);
    c3-= a5-x;
    if(c3 < 0)
	return 0;
    return 1;

}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	cout << (solve() ? "YES\n" : "NO\n");
    }
    return 0;
}