#include <iostream>
#include <string>

using namespace std;

int masks[105];

int get_mask (const string &x) {
    int p = 0;
    for (auto it: x)
        p |= (1 << (it - 'a'));

    return p;
}

int l[1005];

int main()
{
    ios_base :: sync_with_stdio(false);
    int n = 0;

    string aux;

    cin >> n;
    for (int i = 0; i < n; ++ i) {
        cin >> aux;
        masks[i] = get_mask(aux);

        l[i] = aux.size();
    }

    int best= 0;

    int aa, vine;
    for (int i = 0; i < 26; ++ i)
        for (int j = 0; j < i; ++ j) {
            aa = (1 << i) + (1 << j);

            vine = 0;
            for (int k = 0; k < n; ++ k)
                if ((masks[k] & (~aa)) == 0)
                    vine += l[k];

            if (vine > best)
                best = vine;
        }
    cout << best << '\n';

    return 0;
}