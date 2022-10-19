#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'
#define len(a) a.size()
#define cs(a) cout << "Case #" << a << ": "
#define lst(a) a[len(a)-1]
#define tests(a) cin >> a; while(a--)

int tab[110];

int main() {
	int n, m;
	cin >> n >> m;
	while (n--) {
        int t;
        tests(t){
            int a;
            cin >> a;
            tab[a-1]=1;
        }
	}
	bool t=true;
	for (int i = 0; i < m; ++i) {
        if (tab[i]==0) {
            t=false;
        }
	}
	if (t==true) {
        cout << "YES";
	} else {
        cout << "NO";
	}
}