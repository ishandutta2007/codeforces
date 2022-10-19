#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int check=1;int ip;
    for (int i=1;i<=n;i++)
    {
        cin >> ip;
        if (ip==1)
        {
            check=0;
            break;
        }
    }
    if (check==1) cout << "EASY";
    else cout << "HARD";
}