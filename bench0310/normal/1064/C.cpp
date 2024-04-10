#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char s[n+1];
    cin >> s;
    sort(s,s+n);
    cout << s << endl;
    return 0;
}