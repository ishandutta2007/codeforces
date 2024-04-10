#include <iostream>
#include <set>

using namespace std;

set <int> Seth;
multiset <int, greater <int> > sizesh;

set <int> Setw;
multiset <int, greater <int> > sizesw;

int main()
{
    ios_base :: sync_with_stdio(false);

    int w, h, n;
    cin >> w >> h >> n;

    Seth.insert(0);
    sizesh.insert(h);

    Seth.insert(h);

    Setw.insert(0);
    sizesw.insert(w);

    Setw.insert(w);


    char lit;
    int x;

    set <int> :: iterator it;
    int a, b;

    for (int i = 1; i <= n; i++) {
        cin >> lit >> x;

        if (lit == 'H') {
            it = Seth.lower_bound(x + 1);
            b = *it;

            it --;
            a = *it;

            Seth.insert(x);

            sizesh.erase(sizesh.find(b - a));
            sizesh.insert(x - a);
            sizesh.insert(b - x);
        }
        else {
            it = Setw.lower_bound(x + 1);
            b = *it;

            it --;
            a = *it;

            Setw.insert(x);

            sizesw.erase(sizesw.find(b - a));
            sizesw.insert(x - a);
            sizesw.insert(b - x);
        }

        cout << (1ll * (*sizesh.begin()) * (*sizesw.begin())) << '\n';
    }

    return 0;
}