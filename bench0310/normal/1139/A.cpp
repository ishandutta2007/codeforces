#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long cnt=0;
    for(int i=0;i<n;i++)
    {
        if(!((s[i]-'0')&1)) cnt+=(i+1);
    }
    cout << cnt << endl;
    return 0;
}