#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int num[n+1];
    set<int> s;
    for(int i=0;i<n+1;i++) num[i]=0;
    int a;
    for(int o=0;o<m;o++)
    {
        cin >> a;
        s.insert(a);
        num[a]++;
        if((int)s.size()==n)
        {
            s.clear();
            for(int i=1;i<=n;i++)
            {
                num[i]--;
                if(num[i]) s.insert(i);
            }
            cout << 1;
        }
        else cout << 0;
    }
    return 0;
}