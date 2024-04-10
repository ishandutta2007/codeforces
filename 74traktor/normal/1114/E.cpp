#include <bits/stdc++.h>

using namespace std;

#define int long long
int mod = 1e9 + 7;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, op = 0;
    cin >> n;
    int l = -1, r = 1e9 + 1;
    while (r - l > 1){
        int m = (r + l) / 2;
        op++;
        cout << "> " << m << endl;
        int w;
        cin >> w;
        if (w == 1) l = m;
        else r = m;
    }
    set < int > have;
    if (n <= 50){
        for (int j = 1; j <= min(60 - op, n); ++j){
            cout << "? " << j << endl;
            int w;
            cin >> w;
            have.insert(w);
        }
    }
    else{
        for (int j = 0; j < 60 - op; ++j){
            int pos = (rand() * mod + rand()) % n + 1;
            cout << "? " << pos << endl;
            int w;
            cin >> w;
            have.insert(w);
        }
    }
    int D = r - (*have.begin());
    for (int i = 1; i <= sqrt(D); ++i){
        if (D % i == 0){
            int x1 = r - i * (n - 1);
            if (x1 >= 0 && x1 <= (*have.begin())){
                bool f = true;
                for (auto key : have){
                    if ((key - x1) % i != 0){
                        f = false;
                        break;
                    }
                }
                if (f){
                    cout << "! " << x1 << " " << i << endl;
                    return 0;
                }
            }
            int i1 = D / i;
            x1 = r - i1 * (n - 1);
            if (x1 >= 0 && x1 <= (*have.begin())){
                bool f = true;
                for (auto key : have){
                    if ((key - x1) % i1 != 0){
                        f = false;
                        break;
                    }
                }
                if (f){
                    cout << "! " << x1 << " " << i1 << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}