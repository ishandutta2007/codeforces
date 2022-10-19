#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (true) {
        ++n;
        int tab[10];
        for (int i = 0; i < 10; ++i) {
            tab[i]=0;
        }
        int pom=n;
        while (pom>0) {
            ++tab[pom%10];
            pom/=10;
        }
        bool t = true;
        for (int i = 0; i < 10; ++i) {
            if (tab[i]>1) t=false;
        }
        if (t==true) {
            cout << n;
            return 0;
        }
    }
}