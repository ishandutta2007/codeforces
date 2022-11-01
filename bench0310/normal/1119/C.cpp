#include <iostream>

using namespace std;

int ab(int a)
{
    if(a>=0) return a;
    else return -a;
}

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    int a[n][m],b[n][m];
    for(int o=0;o<n;o++) for(int i=0;i<m;i++) cin >> a[o][i];
    for(int o=0;o<n;o++) for(int i=0;i<m;i++) cin >> b[o][i];
    bool good=1;
    for(int o=0;o<n;o++)
    {
        int c=0,d=0;
        for(int i=0;i<m;i++)
        {
            c+=a[o][i];
            d+=b[o][i];
        }
        if(ab(c-d)&1) good=0;
    }
    for(int o=0;o<m;o++)
    {
        int c=0,d=0;
        for(int i=0;i<n;i++)
        {
            c+=a[i][o];
            d+=b[i][o];
        }
        if(ab(c-d)&1) good=0;
    }
    if(good) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}