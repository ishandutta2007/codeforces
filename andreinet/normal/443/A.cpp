#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    string S;
    getline(cin, S);

    vector<int> Count(26, 0);

    for (int i = 0; i < int(S.length()); i ++)
        if (S[i] >= 'a' && S[i] <= 'z')
            Count[S[i] - 'a']++;

    int Ans = 0;
    for (int i = 0; i < 26; i++)
        Ans += (Count[i] > 0);

    cout << Ans << '\n';
}