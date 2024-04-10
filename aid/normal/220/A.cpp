#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    bool sorted = true;
    for(int i = 1; i < n; i++)
        if(a[i] < a[i - 1]) {
            sorted = false;
            break;
        }
    if(sorted) {
        cout << "YES\n";
        return 0;
    }
    int maxa = 0, l = -1, r = -1;
    for(int i = 1; i < n; i++) {
        if(a[maxa] > a[i]) {
            l = maxa;
            r = i;
        }
        else if(a[i] > a[maxa])
            maxa = i;
    }
    swap(a[l], a[r]);
    sorted = true;
    for(int i = 1; i < n; i++)
        if(a[i] < a[i - 1]) {
            sorted = false;
            break;
        }
    if(sorted)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}