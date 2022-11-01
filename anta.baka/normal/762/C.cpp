#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.length();
    int n2 = s2.length();
    vector<int> suff1len(n2,INF);
    for(int i2 = n2-1, i1 = n1-1; i2 >= 0; i2--) {
        while(i1 >= 0 && s1[i1] != s2[i2])
            i1--;
        if(i1 < 0)
            break;
        suff1len[i2] = n1 - i1;
        i1--;
    }
    int oi1 = -1, oi2 = -1;
    for(int i2 = -1, i1 = -1; i2 < n2; i2++) {
        if(i2 != -1)
            while(i1 < n1 && s1[i1] != s2[i2])
                i1++;
        if(i1 == n1)
            break;
        i1++;
        int bl = i2+1, br = n2 - 1;
        while(bl < br) {
            int bm = (bl + br)>>1;
            if(suff1len[bm] <= n1 - i1)
                br = bm;
            else
                bl = bm + 1;
        }
        if(bl < n2 && suff1len[bl] <= n1 - i1 && (oi2 == -1 || i2 + 1 + n2 - bl > oi1 + 1 + n2 - oi2)) {
            oi1 = i2;
            oi2 = bl;
        } else if(oi2 == -1 || i2 + 1 > oi1 + 1 + n2 - oi2) {
            oi1 = i2;
            oi2 = n2;
        }
    }
    if(oi1 == -1 && (oi2 == -1 || oi2 == n2))
        return cout << '-', 0;
    for(int i = 0; i <= oi1; i++)
        cout << s2[i];
    for(int i = oi2; i < n2; i++)
        cout << s2[i];
}