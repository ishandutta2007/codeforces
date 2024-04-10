#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        string a;
        for(int i=0;i<k;i++) a+=(i+'a');
        string s;
        for(int i=0;i<n;i++) s+=a[i%k];
        cout << s << endl;
    }
    return 0;
}