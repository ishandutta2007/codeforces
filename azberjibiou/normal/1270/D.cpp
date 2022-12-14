#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
int N, K;
int that, thatnum, trash;
bool same[505];
int tru, fal;
int main()
{
    gibon
    cin >> N >> K;
    if(K==1)
    {
        cout << "! 1";
        return 0;
    }
    cout << "? ";
    for(int i=1;i<=K;i++)
        cout << i << " ";
    cout.flush();
    cin >> that >> thatnum;
    trash=K+1;
    same[trash]=true;
    for(int i=1;i<=K;i++)
    {
        if(i==that)
            continue;
        int tmp, tmp2;
        cout << "? ";
        for(int j=1;j<=K;j++)
        {
            if(i==j)
                cout << trash << " ";
            else
                cout << j << " ";
        }
        cout.flush();
        cin >> tmp >> tmp2;
        if(tmp==that)
            same[i]=true, tru++;
        else
            same[i]=false, fal++;
    }
    cout << "? ";
    for(int i=1;i<=K;i++)
    {
        if(i<that)
            cout << i << " ";
        else
            cout << i+1 << " ";
    }
    cout.flush();
    int a, b;
    cin >> a >> b;
    if(a!=trash)
    {
        if(same[a])
        {
            if(b>thatnum)
            {
                cout << "! " << fal+1;
            }
            else
                cout << "! " << tru+1;
        }
        else
        {
            if(b<thatnum)
                cout << "! " << fal+1;
            else
                cout << "! " << tru+1;
        }
    }
    else
    {
        tru=0, fal=0;
        for(int i=2;i<=K+1;i++)
        {
            if(same[i])
                tru++;
            else
                fal++;
        }
        if(b>thatnum)
            cout << "! " << fal+1;
        else
            cout << "! " << tru+1;
    }
}