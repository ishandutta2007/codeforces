#include <iostream>

using namespace std;

int main()
{
    int n,d;
    cin >> n >> d;
    int q;
    cin >> q;
    int x,y;
    int sol[q];
    for(int i=0;i<q;i++)
    {
        cin >> x >> y;
        int sum=x+y;
        if(sum<d || sum>(2*n-d))
        {
            sol[i]=0;
            continue;
        }
        if((max(x,y)-min(x,y))<=d)
        {
            sol[i]=1;
            continue;
        }
        sol[i]=0;
    }
    for(int i=0;i<q;i++)
    {
        if(sol[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}