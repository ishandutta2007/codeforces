#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>

using namespace std;

int p[200010];
int kol[200010];
int c[200010];
bool use[200010];

int ukp = 0;

int main()
{
   int n, m, i, j, k, k1;
    char ch;
    bool check;
    cin >> n >> m;
    for (i = 2; i <= n; i++){
        check = true;
        for (j = 2; j * j <= i && check; j++)
            if (i % j == 0)
                check = false;
        if (check){
            c[i] = ukp;
            p[ukp++] = i;
        }
    }
    memset(kol, -1, sizeof kol);
    for (i = 0; i < m; i++){
        cin >> ch;
        cin >> k;
        k1 = k;
        if (ch == '+'){
            if (use[k]){
                cout << "Already on\n";
                continue;
            }
            check = true;
            for (j = 0; p[j] * p[j] <= k1 && j < ukp; j++)
                if (k1 % p[j] == 0){
                    if (kol[j] != -1){
                        cout << "Conflict with " <<  kol[j] << endl;
                        k1 = 0;
                        check = false;
                    }
                    else{
                        while (k1 % p[j] == 0)
                            k1 /= p[j];
                    }
                }
            if (k1 > 1 && check && kol[c[k1]] != -1){
                cout << "Conflict with " <<  kol[c[k1]] << endl;
                k1 = 0;
                check = false;
            }

            if (check){
                cout << "Success\n";
                use[k] = true;
                k1 = k;
                for (j = 0; p[j] * p[j] <= k1 && j < ukp; j++)
                    while (k1 % p[j] == 0){
                        k1 /= p[j];
                        kol[j] = k;
                    }
                if (k1 > 1)
                    kol[c[k1]] = k;
            }
        }
        if (ch == '-'){
            if (use[k] == false){
                cout << "Already off\n";
                continue;
            }
            cout << "Success\n";
            use[k] = false;
            for (j = 0; p[j] * p[j] <= k && j < ukp; j++)
                while (k % p[j] == 0){
                    k /= p[j];
                    kol[j] = -1;
                }
            if (k > 1)

                kol[c[k]] = -1;

        }
    }

    return 0;
}