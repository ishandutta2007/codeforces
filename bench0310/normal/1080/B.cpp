#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    for(int i=0;i<q;i++)
    {
        long long l,r;
        cin >> l >> r;
        long long res=0;
        if(l%2==0)
        {
            res+=l;
            l++;
        }
        if(r%2==1)
        {
            res-=r;
            r--;
        }
        res+=(r-l+1)/2;
        cout << res << endl;
    }
    return 0;
}