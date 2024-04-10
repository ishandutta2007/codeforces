#include <bits/stdc++.h>
using namespace std;
int n,countA,countC,s[105],dem[105];
int main()
{
    int i;
    cin >> n;
    countA=0;countC=0;
    for (i=0;i<=100;i++)
        dem[i]=0;
    for (i=0;i<n;i++)
    {
        cin >> s[i];
        dem[s[i]]++;
    }
    for (i=1;i<=100;i++)
    {
        if (dem[i]==1) countA++;
        if (dem[i]>2) countC++;
    }
    if (countA%2==0)
    {
        cout << "YES" << endl;
        int turn=0;
        for (int i=0;i<n;i++)
        {
            if (dem[s[i]]==1 && turn%2==0)
            {
                cout << 'A';
                turn++;
            }
            else if (dem[s[i]]==1 && turn%2==1)
            {
                cout << 'B';
                turn++;
            }
            if (dem[s[i]]!=1) cout << 'A';
        }
    }
    if (countA%2==1 && countC>0)
    {
        cout << "YES" << endl;
        int turn=0; int check=0;
        for (int i=0;i<n;i++)
        {
            if (dem[s[i]]==1 && turn%2==0)
            {
                cout << 'A';
                turn++;
            }
            else if (dem[s[i]]==1 && turn%2==1)
            {
                cout << 'B';
                turn++;
            }
            if (dem[s[i]]>2 && check==0)
            {
                cout << 'B';
                check=1;
            }
            else if (dem[s[i]]>1) cout << 'A';
        }
    }
    if (countA%2==1 && countC==0) cout << "NO";
}