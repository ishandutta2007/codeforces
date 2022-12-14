#include <bits/stdc++.h>
#define gibon cin.tie(0); ios::sync_with_stdio(false);
using namespace std;
char A[202020];
int Pref[202020][30];
int main()
{
    gibon
    cin >> A+1;
    int len=strlen(A+1);
    int T;
    cin >> T;
    for(int i=1;i<=len;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(A[i]-'a'==j)
            {
                Pref[i][j]=Pref[i-1][j]+1;
            }
            else
                Pref[i][j]=Pref[i-1][j];
        }
    }
    while(T--)
    {
        int a, b;
        cin >> a >> b;
        if(a==b)
        {
            cout << "Yes" << '\n';
            continue;
        }
        if(a==b-1)
        {
            if(A[a]!=A[b])
                cout << "Yes" << '\n';
            else
                cout << "No" << '\n';
            continue;
        }
        if(A[a]!=A[b])
        {
            cout << "Yes" << '\n';
            continue;
        }
        int cnt=0;
        for(int i=0;i<26;i++)
        {
            if(Pref[b][i]-Pref[a-1][i]!=0)    cnt++;
        }
        if(cnt>2)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
}