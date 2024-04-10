#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double



int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i<n; i++) cin>>a[i];
    int pos[n+1];
    for (int i = 0; i<n; i++) pos[a[i]] = i;
    bool win[n+1];
    win[n] = false;
    for (int i = n-1; i>=1; i--)
    {
        int current = pos[i];
        win[i] = false;
        while (current>=i)
        {
            current-=i;
            if (a[current]>i&&win[a[current]]==false) win[i] = true;
        }
        current = pos[i];
        while (current+i<n)
        {
            current+=i;
            if (a[current]>i&&win[a[current]]==false) win[i] = true;
        }
    }
    for (int i = 0; i<n; i++)
    {
        if (win[a[i]]) cout<<"A";
        else cout<<"B";
    }
    
}