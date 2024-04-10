#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x;
    bool easy=1;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        if(x==1) easy=0;
    }
    if(easy) cout << "EASY" << endl;
    else cout << "HARD" << endl;
    return 0;
}