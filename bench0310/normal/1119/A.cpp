#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int c[n];
    for(int i=0;i<n;i++) cin >> c[i];
    if(c[0]!=c[n-1]) cout << n-1 << endl;
    else
    {
        int l,r;
        for(int i=1;i<n;i++)
        {
            if(c[i]!=c[0])
            {
                l=i;
                break;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(c[i]!=c[n-1])
            {
                r=i;
                break;
            }
        }
        cout << max(n-l-1,r) << endl;
    }
    return 0;
}