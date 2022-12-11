#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string mask;
    cin >> mask;
    int n = mask.size();
    if (mask == string(n, '_')) {
        cout << 0 << endl;
        return 0;
    }
    for (int B = 0; B < 5; ++B) {
        vector<bool> coloration(n);
        for (int i = 0; i < n; ++i)
            if (mask[i] == '#')
                coloration[i] = 1;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (i and coloration[i-1])
                continue;
            if (!coloration[i])
                continue;
            if (i - B < 0) {
                ok = false;
                break;
            }
            for (int j = 1; j <= B; ++j)
                coloration[i - j] = true;
        }
        if (!ok)
            continue;
        int dernier = n-1;
        while (!coloration[dernier])
            dernier--;
        
        for (int fin = dernier; fin >= 0; --fin) {
            if (!coloration[fin])
                continue;
            if (fin and coloration[fin-1])
                continue;
            int deb = fin-1;
            while (deb > 0 and !coloration[deb-1])
                --deb;
            // Il faut colorier [deb, fin)
            if (fin - deb == 1) {
                if (!deb) {
                    ok = false;
                    break;
                }
                fin = deb-1;
                continue;
            }

            if (fin - deb == 2) {
                if (!deb) {
                    if (B == 0) {
                        ok = false;
                        break;
                    }
                    coloration[deb] = true;
                } else {
                    ok = false;
                    break;
                }
                continue;
            }

            // fin - deb >= 3
            if (B == 0) {
                ok = false;
                break;
            }
            if (!deb)
                deb--;
            if (B == 1) {
                if ((fin - deb) % 2 == 0) {
                    ok = false;
                    break;
                }
                for (int i = deb + 1; i < fin; i += 2)
                    coloration[i] = true;
                continue;
            } else {
                if ((fin - deb) % 2 == 0) {
                    coloration[deb+1] = coloration[deb+2] = true;
                    for (int i = deb + 4; i < fin; i += 2)
                        coloration[i] = true;
                } else 
                    for (int i = deb+1; i < fin; i += 2)
                        coloration[i] = true;
            }
        }
        if (!ok)
            continue;
        int lenFin = n - dernier-1;
        if (lenFin < B)
            continue;
        if (lenFin == B+1)
            continue;
        if (lenFin > B) {
            if (B == 0) {
                continue;
            }
            if (B == 1) {
                if ((lenFin - B) % 2)
                    continue;
                for (int i = n - B - 1; i > dernier+1; i -= 2)
                    coloration[i] = true;
            } else {
                if ((lenFin- B) % 2 == 0) {
                    for (int i = n - B - 1; i > dernier+1; i -= 2)
                        coloration[i] = true;
                } else {
                    coloration[n-B-1] = coloration[n-B-2] = true;
                    for (int i = n - B - 4; i > dernier+1; i -= 2)
                        coloration[i] = true;
                }
            }
        }
       /* cout << B << endl;
        for (int x : coloration)
            cout << x << ' ';
        cout << endl;
        */vector<int> pattern;
        for (int i = 0; i < n; ++i) {
            if (!coloration[i])
                continue;
            int j = i;
            while (j < n and coloration[j])
                ++j;
            pattern.push_back(j - i);
            i = j;
        }
        cout << pattern.size() << '\n';
        for (int x : pattern)
            cout << x <<  ' ';
        cout<< '\n';
        return 0;
    }
    cout << -1 << endl;
}