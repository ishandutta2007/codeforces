#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int bad[n+1];
    for(int i=1;i<=n;i++)
    {
        cin >> bad[i];
    }
    bool one[n+1];
    for(int i=1;i<=n;i++)
    {
        for(int a=1;a<=n;a++) one[a]=0;
        one[i]=1;
        int next=bad[i];
        while(1)
        {
            if(!one[next]) one[next]=1;
            else
            {
                cout << next << " ";
                break;
            }
            next=bad[next];
        }
    }
    return 0;
}