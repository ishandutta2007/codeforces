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

int a[4];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	for(int i = 0; i < 4; i++)
	    cin >> a[i];
	sort(a, a + 4);
	cout << 1ll * a[0] * a[2] << "\n";
    }
    return 0;
}