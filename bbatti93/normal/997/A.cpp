#include <iostream>

using namespace std;
string s;
int x, y, n, db=0;
int main()
{
    cin >> n >> x >> y;
    cin >> s;
    if(s[0]=='0') db++;
    for(int i=1;i<n;i++) {
        if(s[i]=='0' && s[i-1]=='1') db++;
    }
    if(db==0) cout << 0 << endl;
    else cout << y+min(x,y)*((long long)db-1) << endl;
    return 0;
}