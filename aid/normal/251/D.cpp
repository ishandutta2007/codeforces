#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5, MAXB = 61;
int p[MAXB], ansa[MAXN];
long long a[MAXN], st[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    long long xs = 0;
    for(int i = 0; i < n; i++)
        xs ^= a[i];
    for(int i = 0; i < n; i++) {
        long long aa = 0;
        for(int bit = MAXB - 1; bit >= 0; bit--)
            if(!(xs & (1ll << bit))) {
                aa <<= 1;
                if(a[i] & (1ll << bit))
                    aa++;
            }
        for(int bit = MAXB - 1; bit >= 0; bit--)
            if(xs & (1ll << bit)) {
                aa <<= 1;
                if(a[i] & (1ll << bit))
                    aa++;
            }
        a[i] = aa;
    }
    long long ans = 0, ansVal = 0;
    for(int bit = MAXB - 1; bit >= 0; bit--) {
        int pos = -1;
        for(int i = 0; i < n; i++)
            if(a[i] & (1ll << bit)) {
                pos = i;
                break;
            }
        if(pos == -1)
            continue;
        p[bit] = pos;
        st[pos] ^= (1ll << bit);
        long long val = a[pos];
        a[pos] = 0;
        for(int i = 0; i < n; i++)
            if(a[i] & (1ll << bit)) {
                a[i] ^= val;
                st[i] ^= st[pos];
            }
        if((ansVal ^ val) <= ansVal)
            continue;
        ansVal ^= val;
        ans ^= st[pos];
    }
    for(int i = 0; i < MAXB; i++)
        if(ans & (1ll << i))
            ansa[p[i]] = 1;
    for(int i = 0; i < n; i++)
        cout << ansa[i] + 1 << ' ';
    cout << '\n';
    return 0;
}