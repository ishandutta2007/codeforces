#include <iostream>

using namespace std;

const int MAXX = 1000 * 1000 + 5, K = 5;
int s[K][MAXX];

int getL(long long x) {
    long long l = 0, r = 1000;
    while(l < r - 1) {
        long long m = (l + r) / 2;
        if(m * m * m * m < x)
            l = m;
        else
            r = m;
    }
    return r;
}

int getR(long long x) {
    long long l = 0, r = 1000000;
    while(l < r - 1) {
        long long m = (l + r) / 2;
        if(m * m > x)
            r = m;
        else
            l = m;
    }
    return r;
}

int getMex(int l, int r) {
    if(l >= r)
        return 0;
    for(int i = 0; i < K; i++)
        if(!(s[i][r - 1] - s[i][l - 1]))
            return i;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    s[0][0] = 1;
    s[0][1] = 2;
    for(int i = 2; i < MAXX; i++) {
        int l = getL(i), r = getR(i), gr = getMex(l, r);
        for(int j = 0; j < K; j++)
            s[j][i] = s[j][i - 1];
        s[gr][i]++;
    }
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        if(a == 1)
            continue;
        int l = getL(a), r = getR(a), gr = getMex(l, r);
        ans ^= gr;
    }
    cout << (ans? "Furlo" : "Rublo") << '\n';
    return 0;
}