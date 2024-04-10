#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int cnt1=0 , cnt2=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        
        if(a>b)
        {
            cnt1++;
        }
        if(b>a)
        {
            cnt2++;
        }
    }
    
    if(cnt1==cnt2)
    {
        cout << "Friendship is magic!^^";
    }
    else if(cnt1>cnt2)
    {
        cout << "Mishka";
    }
    else
    {
        cout << "Chris";
    }
}