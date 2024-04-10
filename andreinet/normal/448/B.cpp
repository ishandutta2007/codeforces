#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int Count1[26], Count2[26];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    int ok = 0;

    string S1, S2;
    cin >> S1 >> S2;

    if (S1.length() > S2.length())
        ok = 1;

    int k = 0;
    for (int i = 0; i < int(S1.length()) && k < int(S2.length()); i++)
    {
        if (S1[i] == S2[k])
            k++;
    }

    if (k < int(S2.length()))
    {
        if (ok == 1) ok = 3;
        else ok = 2;
    }

    for (int i = 0; i < int(S1.length()); i++)
    {
        Count1[S1[i] - 'a']++;
    }

    for (int i = 0; i < int(S2.length()); i++)
    {
        Count2[S2[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (Count2[i] > Count1[i]) ok = 0;
    }

    if (ok == 0) cout << "need tree\n";
    else if (ok == 1) cout << "automaton\n";
    else if (ok == 2) cout << "array\n";
    else if (ok == 3) cout << "both\n";
}