#include <iostream>
#include <set>

using namespace std;

const int MAXN = 505;
int ans[MAXN];

int gcd(int a, int b) {
    return b? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    multiset<int, greater<int> > st;
    for(int i = 0; i < n * n; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }
    for(int i = 0; i < n; i++) {
        ans[i] = *st.begin();
        st.erase(st.begin());
        for(int j = 0; j < i; j++)
            for(int k = 0; k < 2; k++) {
                multiset<int, greater<int> >:: iterator
                    it = st.find(gcd(ans[i], ans[j]));
                st.erase(it);
            }
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}