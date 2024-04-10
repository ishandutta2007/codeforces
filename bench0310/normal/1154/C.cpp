#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int w=min(min(a/3,b/2),c/2);
    a-=3*w;
    b-=2*w;
    c-=2*w;
    vector<int> v={0,1,2,0,2,1,0};
    int d=0;
    for(int o=0;o<7;o++)
    {
        vector<int> n={a,b,c};
        int cnt=0;
        for(int i=o;;i=(i+1)%7)
        {
            if(n[v[i]]>0)
            {
                n[v[i]]--;
                cnt++;
            }
            else break;
        }
        d=max(d,cnt);
    }
    cout << 7*w+d << endl;
    return 0;
}