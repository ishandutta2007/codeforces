#include <bits/stdc++.h>

using namespace std;

int n;
bool t[10];

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) {
        char c;
        cin >> c;
        t[c-'0']=true;
    }
    if(t[0]) {
        if(t[1] || t[2] || t[3]) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else {
        if((t[1] || t[2] || t[3]) && (t[7]||t[9])) {
            if((t[1]||t[4]||t[7])&&(t[3]||t[6]||t[9]))cout << "YES" << endl;
            else cout << "NO" << endl;
        } else cout << "NO" << endl;
    }
    return 0;
}