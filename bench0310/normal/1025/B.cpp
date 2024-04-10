#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> s;
    for(int i=0;i<2;i++)
    {
        int a;
        cin >> a;
        for(int j=2;j*j<=a;j++)
        {
            if((a%j)==0) s.insert(j);
            while((a%j)==0) a/=j;
        }
        if(a>1) s.insert(a);
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        set<int> t;
        for(int x:s) if((a%x)==0||(b%x)==0) t.insert(x);
        s=t;
    }
    if(!s.empty()) cout << (*s.begin()) << "\n";
    else cout << "-1\n";
    return 0;
}