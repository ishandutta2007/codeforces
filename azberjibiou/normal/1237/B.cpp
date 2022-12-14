#include <bits/stdc++.h>
using namespace std;
#define gibon ios::sync_with_stdio(false); cin.tie(0);
int N, A[101010], cnt, B[101010], lc, rc=1, Pnt[101010];
bool Asdf[101010];
set <int> s;
int main()
{
    gibon
    cin >> N;
    for(int i=N;i>0;i--)
        cin >> A[i];
    for(int j=N;j>0;j--)
    {
        cin >> B[j];
        Pnt[B[j]]=j;
    }
    for(int i=1;i<=N;i++)
    {
        lc=i;
        if(A[lc]==B[rc])
        {
            rc++;
        }
        else
        {
            Asdf[Pnt[A[lc]]]=true;
            cnt++;
        }
        while(Asdf[rc]==true)
            rc++;
    }
    cout << cnt;
}