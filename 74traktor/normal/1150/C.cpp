#include <bits/stdc++.h>

using namespace std;

int cnt1 = 0, cnt2 = 0;
int a[410005];

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, x;
    cin >> n;
    vector < int > ch;
    for (int i = 2; i <= 410000; ++i){
        if (a[i] == 0){
            ch.push_back(i);
            for (int j = 2 * i; j <= 410000; j += i) a[j] = 1;
        }
    }
    for (int i = 1; i <= n; ++i){
        cin >> x;
        if (x == 1) cnt1++;
        else cnt2++;
    }
    int beg = 0;
    int pos = 0;
    while (cnt1 >= 1 && cnt2 >= 1){
        int delta = ch[pos] - beg;
        int kol = min(cnt2, delta / 2);
        for (int i = 1; i <= kol; ++i) cout << 2 << " ";
        int go = min(cnt1, delta - 2 * kol);
        for (int i = 1; i <= go; ++i) cout << 1 << " ";
        cnt2 -= kol;
        cnt1 -= go;
        beg = ch[pos++];
    }
    for (int i = 1; i <= cnt1; ++i) cout << 1 << " ";
    for (int i = 1; i <= cnt2; ++i) cout << 2 << " ";
	return 0;
}