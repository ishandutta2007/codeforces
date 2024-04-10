#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n,m;
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        if(i%4==1)
        {
            for(int i=0;i<m-1;i++)
            {
                cout << ".";
            }
            cout << "#";
        }
        else if(i%4==3)
        {
            cout << "#";
            for(int i=0;i<m-1;i++)
            {
                cout << ".";
            }
        }
        else
        {
            for(int i=0;i<m;i++)
            {
                cout << "#";
            }
        }

        cout << endl;
    }
}