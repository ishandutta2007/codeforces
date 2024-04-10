#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1005, MAXX = 2000 * 1000 + 5;
int a[MAXN], lDiv[MAXX];
vector<int> pr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 2; i < MAXX; i++) {
        if(!lDiv[i]) {
            lDiv[i] = i;
            pr.push_back(i);
        }
        for(size_t j = 0; j < pr.size() && pr[j] <= lDiv[i]; j++) {
            int p = pr[j] * i;
            if(p >= MAXX)
                break;
            lDiv[p] = pr[j];
        }
    }
    int n;
    cin >> n;
    int cnt1 = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1)
            cnt1++;
    }
    if(cnt1 >= 2) {
        int x = -1;
        for(int i = 0; i < n; i++)
            if(a[i] != 1 && lDiv[a[i] + 1] == a[i] + 1)
                x = a[i];
        cout << (x == -1? cnt1 : cnt1 + 1) << '\n';
        for(int i = 0; i < cnt1; i++)
            cout << 1 << ' ';
        if(x != -1)
            cout << x << ' ';
        cout << '\n';
    }
    else {
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(lDiv[a[i] + a[j]] == a[i] + a[j]) {
                    cout << 2 << '\n' << a[i] << ' ' << a[j] << '\n';
                    return 0;
                }
        cout << 1 << '\n' << a[0] << '\n';
    }
    return 0;
}