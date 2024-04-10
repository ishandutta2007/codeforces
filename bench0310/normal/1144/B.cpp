#include <bits/stdc++.h>

using namespace std;

int ab(int a)
{
    if(a>=0) return a;
    else return -a;
}

int main()
{
    int n;
    cin >> n;
    vector<int> even,odd;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        sum+=a;
        if(a&1) odd.push_back(a);
        else even.push_back(a);
    }
    sort(even.begin(),even.end());
    reverse(even.begin(),even.end());
    sort(odd.begin(),odd.end());
    reverse(odd.begin(),odd.end());
    if(ab(odd.size()-even.size())<=1) cout << 0 << endl;
    else if(even.size()>odd.size())
    {
        for(int i=0;i<(int)odd.size();i++) sum-=odd[i];
        for(int i=0;i<(int)odd.size()+1;i++) sum-=even[i];
        cout << sum << endl;
    }
    else if(odd.size()>even.size())
    {
        for(int i=0;i<(int)even.size();i++) sum-=even[i];
        for(int i=0;i<(int)even.size()+1;i++) sum-=odd[i];
        cout << sum << endl;
    }
    return 0;
}