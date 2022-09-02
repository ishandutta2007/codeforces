#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    string a, b;
    cin>>a>>b;
    int counter = 0;
    int idx = 0;
    while (idx<n)
    {
        if (idx==n-1) {counter+=(a[n-1]!=b[n-1]); idx++;}
        else
        {
            if (a[idx]==b[idx]) idx++;
            else 
            {
                if (a[idx+1]==b[idx]&&a[idx]==b[idx+1]) {counter++; idx+=2;}
                else {counter++; idx++;}
            }
        }
    }
    cout<<counter;
}