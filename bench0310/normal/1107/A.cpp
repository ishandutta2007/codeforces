#include <iostream>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        string s;
        cin >> n >> s;
        if(s.size()==2)
        {
            if(s[0]<s[1]) cout << "YES\n2\n" << s[0] << " " << s[1] << endl;
            else cout << "NO" << endl;
        }
        else
        {
            cout << "YES\n2\n" << s[0] << " ";
            for(int i=1;i<n;i++) cout << s[i];
            cout << endl;
        }
    }
    return 0;
}