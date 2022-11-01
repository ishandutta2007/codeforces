#include <iostream>

using namespace std;

int a[16];

bool good(int l,int r)
{
    bool ok=1;
    for(int i=l;i<r;i++) if(a[i]>a[i+1]) ok=0;
    return ok;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int res=0;
    for(int o=1;o<=n;o*=2)
    {
        for(int i=0;(i+o-1)<n;i+=o)
        {
            if(good(i,i+o-1)) res=o;
        }
    }
    cout << res << endl;
    return 0;
}