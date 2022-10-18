#include <bits/stdc++.h>

using namespace std;

set<int> S;

const int maxs = 10000000;
stringstream in;
char buf[maxs];

int main()
{
    int N; scanf("%d", &N);
    for( int i = 1; i <= N; i++ )
    {
        int tmp; scanf("%d", &tmp);
        while( S.find(tmp) != S.end() )
        {
            S.erase(tmp);
            tmp++;
        }
        S.insert(tmp);
    }
/*
    for( set<int>::iterator it = S.begin(); it != S.end(); it++ )
        cout << *it << endl;
*/
    cout << S.size() << "\n";

    return 0;
}