#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define out(x) cout << "x = " << x << endl

using namespace std;

int frecva[26];
int frecvb[26];
int frecvc[26];

int frecvauxa[26];

void get_frecv (const string &a, int frecv[26]) {
    for (int i = 0; i < 26; i++)
        frecv[i] = 0;
    for (int i = 0; i < a.size(); i++)
        frecv[a[i] - 'a'] ++;
}

int subtract () {
    for (int i = 0; i < 26; i++) {
        frecva[i] -= frecvb[i];

        if (frecva[i] < 0)
            return -1;
    }

    int minima = 100005;
    for (int i = 0; i < 26; i++)
        if (frecvc[i] && frecva[i] / frecvc[i] < minima)
            minima = frecva[i] / frecvc[i];
    return minima;
}

void subtractb () {
    for (int i = 0; i < 26; i++)
        frecvauxa[i] -= frecvb[i];
}

int subtractc () {
    for (int i = 0; i < 26; i++)
        frecvauxa[i] -= frecvc[i];
}

int main()
{
    ios_base :: sync_with_stdio(false);

    string a, b, c;
    cin >> a >> b >> c;

    get_frecv(a, frecva);
    get_frecv(a, frecvauxa);
    get_frecv(b, frecvb);
    get_frecv(c, frecvc);

    int countc = 100005;
    for (int i = 0; i < 26; i++)
        if (frecvc[i] && frecva[i] / frecvc[i] < countc)
            countc = frecva[i] / frecvc[i];

    int best = countc;
    int countb = 0;

    int aux;
    for (int i = 1; i < 100005; i++) {
        aux = subtract();

        if (aux > -1) {
            if (aux + i > best) {
                best = aux + i;

                countb = i;
                countc = aux;
            }
        }
        else
            break;
    }

    for (int i = 0; i < countb; i++) {
        subtractb();
        cout << b;
    }

    for (int i = 0; i < countc; i++) {
        subtractc();
        cout << c;
    }

    for (int i = 0; i < 26; i++)
        while (frecvauxa[i]) {
            cout << (char)(i + 'a');
            frecvauxa[i] --;
        }

    cout << '\n';
    return 0;
}