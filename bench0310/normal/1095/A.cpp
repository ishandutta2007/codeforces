#include <iostream>

using namespace std;

int main()
{
    int n;
    string s,res;
    cin >> n >> s;
    int jump=0;
    for(int i=0;i<n;i+=jump)
    {
        res+=s[i];
        jump++;
    }
    cout << res << endl;
    return 0;
}